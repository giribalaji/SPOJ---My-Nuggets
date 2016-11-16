int main()
{
        int t;
        long int n;
        scanf("%d",&t);
        
        while(t--)
        {
        		int a[1010] = {0};
        		memset(a,0,sizeof(a));
		        scanf("%d",&n);
                long int i,j,tmp;
				//count=0;
                for(i=0;i<n;i++)
                {
                        scanf("%d",&j);
                       if(a[j]==0 || j == n-1)
					    a[j]++;
					    else
					    a[n-j-1]++;
                                         }
               
            /*   for(i=0;i<=n;i++)
                {
                        printf("%d\n",a[i]);
                       
                                         }*/
			     int flag=1;              
                if(a[0]!=0 || a[n-1]!=2)
                {
                	flag=0;
                }
                
                if(flag)
                {
                	for(i=1;i<n-1;i++)
                	{
                		if(a[i]==0)
                		{
                			flag=0;
                			break;
                		}
                	}
                }
                
                if(flag)
                {
                	printf("YES\n");
                }
                else
				{
			printf("NO\n");
				}	
		
		
		}
	
	return 0;
}
