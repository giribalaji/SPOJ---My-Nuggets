
int t,x,y,n,w,p1,p2;
int max(int a, int b)
{
    return (a > b)? a : b;
}

int fun(int w, int f)
{
	if(w<=0)
		return 1;
	else
		{
			if(f==1)
			{
			return max((p1*fun(w-x,2)),(100-p1)*fun(w,2));			
			}
			else
			{
				return max((p2*fun(w-y,1)),(100-p2)*fun(w,1));
			}
		}
}



int main()
{
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d %d %d %d %d",&x,&y,&n,&w,&p1,&p2);
		
		int ans=fun(w,1);
		printf("%d\n",ans);
		
	}
	
	
	return 0;
	
}
