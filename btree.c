#include<stdio.h>
//char *s;
int traverse(char *s)
{
    printf("%s\n",s);
	if ((*s=='l'))
		return 0;
	int l=traverse(s+1);
	int r=traverse(s+2);
	if(l>r)
		return l+1;
	else
		return r+1;
	
		
}

int main()
{

int t,n ;
scanf("%d", &t);
while(t-->0)
{

	n=0;
	char arr[100001];
	scanf("%s",arr);
 //   char *s=arr;
	n=traverse(arr);
	printf("%d\n",n);
}
	return 0;
}
	
	
