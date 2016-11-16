
int rl=0,rh,cl=0,ch;
int mi,mc;
int a[25][25];
void spiral_print(int i, int j, int d)
{

if(i==mi&&j==mc)

{
printf("%d\n",a[i][j]);
return;
}


	if(d==1) //right
	{
		if(i<rl||i>rh||j<cl||j>ch) //change to start from top
		{
		rl++;
		j--;
		i++;
		d=4;
			spiral_print(i,j,d);	
		
		}
		else
		{
			printf("%d\n",a[i][j]);
			spiral_print(i,j+1,d);
		}
		
	}
	else if(d==2)//left
	{
	if(i<rl||i>rh||j<cl||j>ch) //change to start from down
		{
		rh--;
		j++;
		i--;
		d=3;
			spiral_print(i,j,d);	
		
		}
		else
		{
			printf("%d\n",a[i][j]);
			spiral_print(i,j-1,d);
		}	
	}
	else if(d==3) //start from down
	{
	
	if(i<rl||i>rh||j<cl||j>ch) //change to start from right
		{
		j++;
		i++;
		d=1;
		cl++;
			spiral_print(i,j,d);	
		
		}
		else
		{
			printf("%d\n",a[i][j]);
			spiral_print(i-1,j,d);
		}	
	}
	else //if(d==4)//start from top
	{
	if(i<rl||i>rh||j<cl||j>ch) //change to start from left
		{
		j--;
		i--;
		d=2;
		ch--;
			spiral_print(i,j,d);	
		
		}
		else
		{
			printf("%d\n",a[i][j]);
			spiral_print(i+1,j,d);
		}	
	}	




}


int main()
{
	int i,j,k,l;
	scanf("%d %d",&k,&l);
	rh=k-1;ch=l-1;
	mi=rh/2;mc=ch/2;
	if(k%2==0&&l%2==0)
	{
		mi=k/2;
		mc=(l/2)-1;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<l;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	spiral_print(0,0,1);
	
	return 0;
}
