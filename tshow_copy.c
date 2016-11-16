void main()
{

int t;
    long long int num,temp,n,i,j,ans,k,rem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&num);
        temp=0,n=0;

        //calculating the value of n(length)
        while(temp<num)
        {
            n=n+1;
            temp=pow(2,n);
            printf("%lld \n",temp);
        }
        temp=pow(2,n)-2;
        printf("%lld %lld\n",n,temp);
        
    }
    
}
