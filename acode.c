#include<stdio.h>
#include<string.h>

#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))
int fun(char *inp , int n)
{
	int a[100000],i=0, var=0,t1;

	if(inp[i]=='0')
	{
	//	printf("giri\n");
		return 0;
}
	a[0]=1,a[1]=2;

	if(n==1)
		return 1;
		
		if(n==2)
	{
		
		 
		if(inp[1]!='0')
		{
			int tmp=(inp[0]-48)*10;
			tmp=tmp+(inp[1]-48);
			if(tmp<=26)
				return 2;	
			else
				return 1;
		}
		
			
		 
		 if(inp[0]=='1'||inp[0]=='2')
		 	return 1;
		else
			return 0;
		
		
		i++;
		
	}
	
	if (inp[1]=='0'||inp[0]>'2')
		a[1]=1;
	if (inp[1]=='0'&& inp[0]>'2')
		return 0;
	var=a[1];
	for(i=2;i<n;i++)
	{
		
		t1=(inp[i]-'0');
	//	printf("%c --- %d\n",inp[i],t1);
	//if(t1>=1&&t1<=6&&inp[i-1]<'3'&&inp[i-1]!='0')
		if(inp[i]!='0'&&inp[i-1]<'3'&&inp[i-1]!='0')
		{
			//a[i]=MAX(var,a[i-1]+a[i-2]);
			a[i]=a[i-1]+a[i-2];
	//		printf("-- %d\n",a[i]);
			var=a[i];
		}
		else if(inp[i]=='0')		
		{
			t1=(inp[i-1]-'0')*10;
			//printf("%d",t1);
			if(t1>=1&&t1<=26)
			{
				a[i]=a[i-2];
				var=a[i];
			}
		   else
			  return 0;
		}
		else
		{
			a[i]=var;
		}
	}
	
	

		return a[i-1];

}

int main()
{
	char arr[100000];
	scanf("%s",arr);
	while(strcmp(arr,"0")!=0)
	{
		//printf("%s\n",arr);
		int n=strlen(arr);
		int k=fun(arr,n);
		printf("%d\n",k);
		scanf("%s",arr);
	
}
return 0;

}
