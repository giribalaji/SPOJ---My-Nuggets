1#include<stdio.h>

int main()
{
long int arr[10000],i,temp=0,t,n,flag=0;

scanf("%d",&t);

while (t--)
{
flag=0;
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d",&temp);
arr[i]=(i==0)?temp:temp+arr[i-1];
}

for(i=1;i<n-1;i++)
{
if(arr[i-1]==(arr[n-1]-arr[i]))
{

//printf("Index found : %d and value : %d\n",i,arr[i]-arr[i-1]);
printf("YES\n");
flag=1;
break;
}
}
if(flag==0)
{

	printf("NO\n");

}
//printf("giri");
}
return 0;
}
