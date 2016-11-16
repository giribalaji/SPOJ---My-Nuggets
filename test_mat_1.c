typedef struct
{
  int a[10][10];
}srt;

//void func (Array_by_val x);


int func(srt x,int n)
{
	if(n==1)
	{
		x.a[0][1]=5;
		x.a[1][1]=7;
	}
	else if (n==2)
	{
//		memset(a,0,sizeof(a[0])*5);
	 //a[][6]={0};
		x.a[0][1]=10;
	x.a[1][1]=11;
	x.a[2][2]=25;
		func(x,3);
		func(x,1);
		srt x;
	//	x.a[10][10]= {0};
		memset(x.a,0,sizeof(x.a[0][0])*10*10);
		func(x,3);
		return 0;
	}
	else
	{
		printf("Value %d  %d  %d\n",x.a[0][1],x.a[1][1],x.a[2][2]);
		return 0;
	}
printf("Value %d  %d  %d\n",x.a[0][1],x.a[1][1],x.a[2][2]);
//	func(x,2);
//	printf("Value %d  %d\n",a[0],a[1]);
//	func(x,3);
}


int main()
{
	int a[5]={0};
	memset(a,0,sizeof(a));
	int n=1;
	//printf("Value %d  %d\n",a[0],a[1]);
	int b[6][6];
	srt x;
	func(x,1);
	func(x,2);
	return 0;
}
