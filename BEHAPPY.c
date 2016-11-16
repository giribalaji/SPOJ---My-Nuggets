int A[25];
int B[25];
static int count;

int rec(m,n)
{
	int count=0,i;
	if(n==0 && m==0)
	{
	//printf("Values %d %d \n",A[m+1],B[m+1]);
		return 1;
	}
	if(m<0||n<0)
	{
		return 0;
	}
for(i=A[m];i<=B[m];i++)
{
//	printf("Values %d %d \n",m,n-i);
	count=count+rec(m-1,n-i);
}
return count;
}


int main()
{
 int m,n,i,j;
 
 scanf("%d %d",&m,&n);
 
 while(m&&n)
  {
 	
for(i=0;i<m;i++)	 
{
	scanf("%d %d",&A[i],&B[i]);
	}
	 
printf("%d\n",rec(m,n)); 
 	
scanf("%d %d",&m,&n);
 }



	return 0;
}
