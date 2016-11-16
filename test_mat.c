
int func(int a[6][6],int n)
{
	if(n==1)
	{
		a[0][1]=5;
		a[1][1]=7;
	}
	else if (n==2)
	{
//		memset(a,0,sizeof(a[0])*5);
	 //a[][6]={0};
		a[0][1]=10;
	a[1][1]=11;
		func(a,3);
		return 0;
	}
	else
	{
		printf("Value %d  %d\n",a[0][1],a[1][1]);
		return 0;
	}
printf("Value %d  %d\n",a[0][1],a[1][1]);
	func(a[6][6],2);
//	printf("Value %d  %d\n",a[0],a[1]);
	func(a,3);
}


int main()
{
	int a[5]={0};
	memset(a,0,sizeof(a));
	int n=1;
	//printf("Value %d  %d\n",a[0],a[1]);
	int b[6][6];
	func(b,1);
	return 0;
}
