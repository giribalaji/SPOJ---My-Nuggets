#include<stdio.h>
#include<string.h>
char str[10][10]={"inaq","cdef","bias","ghty"};
char s[5]={"india"};
int func(int i,int r,int c)
{
/*	static int z=0;
	z++;
	printf("%d\n",z);*/
	if(i==4)
	{
		return 1;
	}
	 if (((r>=0)&&(r<4))||((c>=0)&&(c<4)))
			{
				//r--;
				if(s[i+1]==str[r-1][c])
				{	
					i++;
					r--;
					func(i,r,c);
				}
			}
	else if(((r>=0)&&(r<4))||((c>=0)&&(c<4)))
				{
					//c++;r++;
					if(s[i+1]==str[r+1][c+1])
					{
						i++;
						c++;r++;
						func(i,r,c);
					}			
				}
	else if(((r>=0)&&(r<4))||((c>=0)&&(c<4)))
				{
					//c--;r++;
					if(s[i+1]==str[r+1][c-1])
					{
						i++;
						c--;r++;
					func(r,c,i);
					}
			
				}
	else if(((r>=0)&&(r<4))||((c>=0)&&(c<4)))
				{
					//r--;c++;
					if(s[i+1]==str[r-1][c+1])
					{	
						i++;
						r--;c++;
						func(r,c,i);
					}			
				}
				

	else
	{
		return 0;
	}
}
main()
	{
		//printf("in main");
		char ch;
		int i=0,r=0,c=0,ret;
		ch=s[i];
		//printf("%c\n",ch);
		for(r=0;r<4;r++)
			{
			 for(c=0;c<4;c++)
				{
					if(ch==s[i])
					  {
					  /*	static int k=0;
					  	k++;
					  	printf("before calling function %d\n", k);*/
					  	printf("%d %d %d\n",i,r,c);
					  	ret=func(i,r,c);
					  }	
					 if (ret==1)
					{
						break;
						printf("string is found");
					}
					
					if (ret==0)
					printf("return is zero \n");
					continue;
						
				}
			}
			if((r>=3)&&(c>=3))
			printf("string not found");
			
	}
