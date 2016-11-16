#include<stdio.h>

int main()
{
	int k,l,z=0,a,b,q,r;
	scanf("%d %d",&k,&l);
	while(k!=-1 && l !=-1)
	{
	/*	if(k==z || l==z)
		{
			if(k==z && l==z)
			{
				printf("0\n");
			}
			else if (k==z)
				printf("%d\n",l);
			else
				printf("%d\n",k);
		}
	
		else if(k==1 || l==1)
		{
			if(k==1 && l==1)
			{
				printf("1\n");
			}
			else if (k==1)
				printf("%d\n",l-2);
			else
				printf("%d\n",k-2);
		}*/
	
	//	else
	//	{
			if (k > l)
				{
				a=k;
				b=l+1;
				}	
			else 
			{
				a=l;
				b=k+1;
			}
				q=a/b;
				r=a%b;
			 if (r==0)
				printf("%d\n",q);
			else
				printf("%d\n",q+1);	
				
	//	}

	scanf("%d %d",&k,&l);
	}
	
	


return 0;
}
