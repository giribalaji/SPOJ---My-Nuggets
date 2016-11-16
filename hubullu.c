#include<stdio.h>
int main()
{
	long long int n=2;int k;
	
	//printf("%d",n/2);
	scanf("%d %d",&n,&k);
	printf("%lld %d\n",n,k);
	
	char *p[2]={"Airborne wins.\n","Pagfloyd wins.\n"};
	char *p1[2]={"Pagfloyd wins.\n","Airborne wins.\n"};
	char **q=p;
	
	
	
	if(k)
	{
	printf("Giri\n");
	q=p1;	
	}
	
/*	switch(k)
	{
		case 0:
			char *p[2]={"Airborne wins.\n","Pagfloyd wins.\n"};
			break;
		case 1:
			char *p[2]={"Pagfloyd wins.\n","Airborne wins.\n"};
			break;
	}*/
	
	printf("%s",q[n]);
	return 0;
}
