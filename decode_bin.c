#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Wave file header */
#pragma pack(1)
struct pcm_wave{
    char chunkId[4];
    int chunkSize;
    char format[4];
    char subchunk1Id[4];
    int subchunk1Size;
    short audioFormat;
    short noChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char subchunk2Id[4];
    int subchunk2Size;
};

enum bands
{
    NARROW_BAND,
    WIDE_BAND,
    SUPER_WIDE_BAND,
    FULL_BAND,
    MAX_BAND
};

int band_rate[MAX_BAND] =
{
    8000,       // NARROW_BAND
    16000,      // WIDE_BAND
    24000,      // SUPER_WIDE_BAND
    48000,      // FULL_BAND
};

#define PCM_SUBCHUNK1_ID_SIZE 16
#define PCM_FORMAT 0x0001

static int bin_file_sz = 0;
static int is325 = 0;

int pay_load_check(unsigned char **buffer, unsigned char *bstart, short *id, int number_streams)
{
	static unsigned char header[2] = {0x12, 0x34};    /* Header */
    int found;
    int ret = -1;
	int path_id = 0;
	int starting_address = *buffer;
	int end_address = 0;
	int pay_load_length = 0;
    unsigned char *ptr = *buffer;
    unsigned char data;
	int i = 0;
	found = 0;
	
	
	while (ptr < (bstart + bin_file_sz))
    {
        data = *ptr++;
        if (data == header[0])
        {
            data = *ptr++;
			
            if (data == header[1])
            {	
				data = *ptr++;
				path_id = data;
				data = *ptr++;
				path_id |= ((data & 0xf0) << 4);
				
				for(i=0;i<number_streams;i++)
				{
					if(path_id == id[i])
					{
						found = 1;
						break;
					}            
				}
				if(found)
					break;
			}
			else
			{
				*ptr--;
			}
        }
		
	}
	if(found)
		{
			end_address = ptr + 4;
			pay_load_length = (end_address - starting_address);
		}
	
	
	return pay_load_length;
}

int find_next_frame(unsigned char **buffer, unsigned char *bstart, short *next_id, int *next_len, short *next_pktCtr)
{
    static unsigned char header[2] = {0x12, 0x34};    /* Header */
    int found;
    int ret = -1;
    unsigned char *ptr = *buffer;
    unsigned char data;

    /* Search for header */
    found = 0;
    while (ptr < (bstart + bin_file_sz))
    {
        data = *ptr++;
        if (data == header[0])
        {
            data = *ptr++;
            if (data == header[1])
            {
                found = 1;
                break;
            }
			else
			{
				*ptr--;
			}
        }
    }

    /* Check whether we reached the end of buffer */
    if ((ptr + 6 > (bstart + bin_file_sz)) || (ptr > (bstart + bin_file_sz)))
    {
        *buffer = ptr;
        return ret;
    }

    if (found)
    {
        /* Get the ID */
        data = *ptr++;
        *next_id = (short)data;

        /* Get the packet counter */
        data = *ptr++;
		if (!is325)
		{
			*next_id |= (short)((data & 0xf0) << 4);
			*next_pktCtr = (short)(data & 0xf);
		}
		else
		{
			*next_pktCtr = (short)(data & 0xff);
		}

        /* Get the length */
        data = *ptr++;
        *next_len = (short)data;
        data = *ptr++;
        *next_len |= (short)(data << 8);
        data = *ptr++;
        *next_len |= (short)(data << 16);
        data = *ptr++;
        *next_len |= (short)(data << 24);

        switch (*next_len)
        {
            case 160:
			case 256:
            case 320:
			case 480:
            case 640:
            case 1280:
                ret = 0;
                break;

            default:
                ret = 2;
        }
    }

    *buffer = ptr;

    return ret;
}

int main(int argc, char *argv[])
{
    FILE *bin_fp = NULL;
    FILE *out_fp[16] = {NULL};
	FILE *log_fp = NULL;
    unsigned char *raw_buf = NULL;
    unsigned char *buf = NULL;
    struct pcm_wave wave_header[16];
    int number_streams = 0;
    short stream_id[16] = {0};
    char filename[256];
    char bin_filename[256];
    char *dot;
    int band_idx;
    int ret = -1;
    int i;
    int first_run = 0;
    int str_rcv = 0;
    int write_wav = 0;
	int file_sz[16] = {0};
	int *cur_ptr[16] = {0};
	int cur_len[16] = {0};
	short first_packet_check = 1;
	int first_packet = 0;
	int cur_id[16] = {0};
	short output_file = 1;
	short write_streams = 0;
	short previous_pktcntr = 0;
	short pkt_chk[16] = {0};
	int err_pkt[16] = {0};
	short is_new_packet = 0;
	short diff_pkt = 0;
	short start_chk = 0;
	short received_packets = 0;
	int previous_id = 0;
	int address;
	short repeated_packet = 0;
	short header_check = 0;
	int pay_load_length = 0;
	int lesser_payload = 0;

    if ((argc < 4) || (!strcmp(argv[1], "-h")))
    {
        printf("usage:\tdecode_bin.exe <bin filename> <number of streams> <nb/wb/swb/fb> <write wav: y/n> <325/705>\n");
        goto exit;
    }

    /* Get the command line arguments */
    strcpy(bin_filename, argv[1]);
    number_streams = atoi(argv[2]);
    if (!(strcmp(argv[3], "nb")))
        band_idx = NARROW_BAND;
    else if (!(strcmp(argv[3], "wb")))
        band_idx = WIDE_BAND;
    else if (!(strcmp(argv[3], "swb")))
        band_idx = SUPER_WIDE_BAND;
    else if (!(strcmp(argv[3], "fb")))
        band_idx = FULL_BAND;
    else
    {
        printf("usage:\tdecode_bin.exe <bin filename> <number of streams> <nb/wb/swb/fb> <write wav: y/n>\n");
        goto exit;
    }

    if (argv[4])
    {
        if (!(strcmp(argv[4], "y")))
            write_wav = 1;
        else if (!(strcmp(argv[4], "n")))
            write_wav = 0;
        else
        {
            printf("usage:\tdecode_bin.exe <bin filename> <number of streams> <nb/wb/swb/fb> <write wav: y/n>\n");
            goto exit;
        }
    }

	if (argv[5])
	{
		if(!(strcmp(argv[5], "325")))
			is325 = 1;
		else if(!(strcmp(argv[5], "705")))
			is325 = 0;
		else
		{
			printf("please specify chip: 325/705\n");
			printf("usage:\tdecode_bin.exe <bin filename> <number of streams> <nb/wb/swb/fb> <write wav: y/n>\n");
			goto exit;
		}
	}

    bin_fp = fopen(bin_filename, "rb");
    if (bin_fp == NULL)
    {
        printf("Error opening bin file\n");
        goto exit;
    }

    /* Strip the extension from bin_filename */
    if ((dot = strrchr(bin_filename, '.')))
        *dot = '\0';

    /* Generate wave header */
    if (write_wav)
    {
        for(i = 0; i < number_streams; i++)
        {
            memset(&wave_header[i], 0, sizeof(wave_header[i]));

            memcpy(wave_header[i].chunkId, "RIFF", sizeof(wave_header[i].chunkId));
            memcpy(wave_header[i].format, "WAVE", sizeof(wave_header[i].format));
            memcpy(wave_header[i].subchunk1Id, "fmt ", sizeof(wave_header[i].subchunk1Id));
            wave_header[i].subchunk1Size = PCM_SUBCHUNK1_ID_SIZE; /* PCM fmt has sub fields of 16 bytes */
            wave_header[i].audioFormat = PCM_FORMAT;
            wave_header[i].sampleRate = band_rate[band_idx];

            wave_header[i].noChannels = 1;
            wave_header[i].bitsPerSample = 16;
            wave_header[i].byteRate = (wave_header[i].sampleRate * wave_header[i].noChannels * wave_header[i].bitsPerSample) / 8;
            wave_header[i].blockAlign = (wave_header[i].noChannels * wave_header[i].bitsPerSample) / 8;
            memcpy(wave_header[i].subchunk2Id, "data", sizeof(wave_header[i].subchunk2Id));
        }
    }

    /* Find the bin file size */
    fseek(bin_fp, 0L, SEEK_END);
    bin_file_sz = ftell(bin_fp);
    fseek(bin_fp, 0L, SEEK_SET);

    /* Read the bin file */
    raw_buf = (unsigned char*)malloc(bin_file_sz);
    fread(raw_buf, sizeof(char), bin_file_sz, bin_fp);
    fclose(bin_fp);
	 
    first_run = 1;
    buf = raw_buf;
	address = raw_buf;

	sprintf(filename, "%s.%s", bin_filename,"txt");
    log_fp = fopen(filename, "a+");

	printf("\n ----Decode tool for streaming---\nVersion 1.0.1");
    while(buf < (raw_buf + bin_file_sz))
    {
        short id, pktCtr;
        int len;

        ret = find_next_frame(&buf, raw_buf, &id, &len, &pktCtr);
			/*get the first packet counter*/
		if(first_packet_check)
		{
			first_packet = pktCtr;
			first_packet_check = 0;
		}
		if(ret == -1)
		{
			printf("\nempty file or reached end of the file\n");
			goto exit;
		}
		if (ret == 0)
        {
            if (buf >= (raw_buf + bin_file_sz))
                goto exit;
			/*verifying the first set of streams */
            if (first_run)
            {
                stream_id[str_rcv] = id;
				cur_ptr[str_rcv] = buf;
				cur_id[str_rcv] = id;
				cur_len[str_rcv] = len;
				pkt_chk[str_rcv] = 1;
				/* Check whether all the streams have been received */
				
				if((first_packet != pktCtr) && (first_run)) 
				{
					first_run = 1;
					buf = buf-8;
					str_rcv = 0;
					first_packet_check = 1;
					continue;
				}
				if (++str_rcv == number_streams)
                    first_run = 0;

                /* Create the output file for the streams ensuring that all the streams are received in correct order*/
                if (!first_run) 
                {
					for(i = 0; i < number_streams; i++)
					{
						sprintf(filename, "%s_%x.%s", bin_filename, cur_id[i], (write_wav ? "wav" : "pcm"));
						out_fp[i] = fopen(filename, "wb");
						if (out_fp[i] == NULL)
						{
							printf("error creating output file - %s\n", filename);
							goto exit;
						}
						/* Write the header to the file */
						if (write_wav)
							fwrite(&wave_header[i], 1, sizeof(wave_header[i]), out_fp[i]);
					}
					output_file = 0;
					
					start_chk = 1;
					previous_pktcntr = pktCtr;
                }
				header_check = 1;
            }

			/* checking for the error packets after receiving the first set of streams with same packet counter number */
			if(start_chk)
				{
					pay_load_length = pay_load_check(&buf, raw_buf , stream_id ,number_streams);
					if(pay_load_length < len)
					{
						//printf("lesser payload %d in path id %x at offset %x \n", pay_load_length,id,buf-address);
						fprintf(log_fp,"%s %s %d %s %x %s %x","\n","lesser payload",pay_load_length,"in path id",id,"at offset",buf-address);
						lesser_payload = 1;
					}
					if(pay_load_length > (len+8))
					{
						//printf("pay load length is larger than expected %d in path id %x at offset %x \n",pay_load_length,id,buf-address);
						fprintf(log_fp,"%s %s %d %s %x %s %x","\n","pay load length is larger than expected",pay_load_length,"in path id",id,"at offset",buf-address);
					}
					header_check = 0;
					for(i = 0; i < number_streams; i++ )
					{
						if(stream_id[i] == id)
						{
							header_check = 1;
							break;
						}
					}
					if(!header_check)
					{
						buf = buf - 6;
						break;
					}
					if((header_check) && (!lesser_payload))
					{
					if(repeated_packet > number_streams)
					{
						printf("\n packet counter number %x repeated at %x",previous_pktcntr,(buf-address - 7 - ((repeated_packet-number_streams)*(len + 8))));
						fprintf(log_fp,"%s %s 0x%x %s %x %s","\n","packet counter number",previous_pktcntr,"repeated at",(buf-address - 7 - ((repeated_packet-number_streams)*(len + 8))),"\n");
					}
					
					/* check if streams are received with a new packet counter number */
					if(previous_pktcntr != pktCtr)
					{
						is_new_packet = 1;
					}
					else
						repeated_packet++;
					if(is_new_packet)
					{
						repeated_packet = 0;
						for(i = 0; i < number_streams; i++)
						{
							/* missing packets by verifying the flags for each streams */
							if((pkt_chk[i]!=1) &&(!lesser_payload))
							{
							err_pkt[i]++;
							
							//printf("\nstream id 0x%x is missing with packet counter number %d at 0x%x ",stream_id[i],previous_pktcntr,(buf-address - 7));
							fprintf(log_fp, "%s %s 0x0%x %s 0x0%x %s 0x%x","\n","path id",stream_id[i],"is missing with packet counter number",previous_pktcntr,"at",(buf-address - 7));
							}
							else
							{
								pkt_chk[i]=0;
								received_packets++;
							}
						}
						
				    /* check if more than one packet is missing */
						diff_pkt = pktCtr - previous_pktcntr;
						if(!is325)
						{
							if(!((diff_pkt == 1) || (diff_pkt == -15)))
							{
								if(diff_pkt<=0)
								{
									diff_pkt = (15-(-diff_pkt)) + 1;

								}
								for(i = 0; i < number_streams; i++)
								{
									err_pkt[i]+= diff_pkt-1;
									fprintf(log_fp, "%s %d %s 0x0%x %s 0x0%x %s 0x%x","\n",diff_pkt-1,"packets of path id",stream_id[i],"are missing after packet counter number",previous_pktcntr,"at",(buf-address - 7));
								}
																
							}
						}
						/* missing packets for ES325 */
						else
						{
							if(!((diff_pkt == 1) || (diff_pkt == -255)))
							{
								if(diff_pkt<=0)
								{
									diff_pkt = (255-(-diff_pkt));
								}
								for(i = 0; i < number_streams; i++)
								{
									err_pkt[i]+= diff_pkt-1;
									fprintf(log_fp, "%s %d %s 0x0%x %s 0x0%x %s 0x%x","\n",diff_pkt-1,"packets of path id",stream_id[i],"are missing after packet counter number",previous_pktcntr,"at",(buf-address - 7));
								}
								
							}
						}
					}
					/* check if all the streams are received or not */
					if((is_new_packet) && (received_packets < number_streams))
					{
						//printf("\n packet drop with packet counter number %d so discarding the stream", previous_pktcntr);
						fprintf(log_fp, "%s %s ox0%x %s %s","\n","packet drop with packet counter number",previous_pktcntr,"so discarding the packets","\n");
						received_packets = 0;  // making received_packets = 0 so that path id's with this packet counter number are discarded from writing in to a wave file
					}
					/* Write to relevant stream id wave file */
					if((is_new_packet) && (received_packets == number_streams))
					{						
						for (i = 0; i < number_streams; i++)
						{
							if (cur_id[i] == stream_id[i])
							{
								fwrite(cur_ptr[i], 1, cur_len[i], out_fp[i]);
								file_sz[i] += len;
							}
						}
					received_packets = 0;
					}
				}	
				}
			
			/* setting flag for each stream received and storing the starting address of the stream */
			if((header_check)&&(!lesser_payload))
			{
				for(i=0;i<number_streams;i++)
			{
				if(stream_id[i] == id)
				{
					cur_ptr[i] = buf;
					cur_len[i] = len;
					cur_id[i] = id;
					pkt_chk[i] = 1;
				}
			}			

			previous_id = id;
			previous_pktcntr = pktCtr;
			is_new_packet = 0;
			}	
		}
		lesser_payload = 0;
	buf = buf - 6;
	}

	

exit:
    /* Complete the wave header and write to the wav file */
    if (write_wav)
    {
        for (i = 0; i < number_streams; i++)
        {
            if (out_fp[i])
            {
                wave_header[i].subchunk2Size = file_sz[i];
                wave_header[i].chunkSize  = 4 + (8 + wave_header[i].subchunk1Size) + (8 + wave_header[i].subchunk2Size);
                fseek(out_fp[i], 0L, SEEK_SET);
                fwrite(&wave_header[i], 1, sizeof(wave_header[i]), out_fp[i]);
                fclose(out_fp[i]);
            }
        }
    }
	printf("\n\\\\\\\\\\\\\\\\total number of packet drops for each path id \\\\\\\\\\\\\\\\\\\\\\\\ \n");
	fprintf(log_fp, " %s %s","\n", "\\\\\\\\\\\\\\\\ packet drops in each stream \\\\\\\\\\\\\\\\\\\\\\\\");
	for(i=0;i<number_streams;i++)
	{
		printf("\n              for path id 0x%x  =  %d",stream_id[i],err_pkt[i]);
		fprintf(log_fp, " %s %s 0x%x %d","\n","total number of packet drops in path id",stream_id[i],err_pkt[i]);
	}
	printf("\n");
	printf("\neach packet drop is listed in %s.txt file \n",bin_filename);
	/* Close the files */
	for(i = 0; i < number_streams; i++)
	{
		if (out_fp[i])
		{
			fclose(out_fp[i]);
			
			fprintf(log_fp,"%s %s %d %s %d %s","\n","stream",stream_id[i],"written with",file_sz[i],"bytes");
		}
	}
    if (bin_fp) fclose(bin_fp);
    if (raw_buf) free(raw_buf);
	if (log_fp) fclose(log_fp);
    return ret;

}
