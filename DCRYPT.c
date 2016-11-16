#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t,k,i,v;
	scanf("%d",&t);
	char l[]="abcdefghijklmnopqrstuvwxyz";
	char u[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char st[100005];
	char *p=st;
	while(t--)
	{
		scanf("%d",&k);
		scanf("%s",p);
		
		if(k<26)
		{
			for(i=0;p[i];i++)		
			{
				if(p[i]!='.')
				{
				
				
				if(p[i]>='a')
				{
				v=(((p[i]-'a')+k)%26);
		//		printf("\n%d -- %c\n",v,l[v]);
					printf("%c",l[v]);
				
				}else
				{
					v=(((p[i]-'A')+k)%26);
			//	printf("\n%d -- %c\n",v,u[v]);	
					printf("%c",u[v]);
			}
			}
			else
			{
				printf(" ");
			}
			
			}
			
		}
		else
		{

			for(i=0;p[i];i++)		
			{
				if(p[i]!='.')
				{
				if(p[i]>='a')
				{
				v=(((p[i]-'a')+k)%26);
		//		printf("\n%d -- %c\n",v,l[v]);
					printf("%c",u[v]);
				
				}else
				{
					v=(((p[i]-'A')+k)%26);
			//	printf("\n%d -- %c\n",v,u[v]);	
					printf("%c",l[v]);
			}				

					
			}
			else
			{
				printf(" ");
			}
			
			}
		}
		
		printf("\n");
	}
	return 0;
}
