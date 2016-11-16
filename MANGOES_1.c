 #include<stdio.h>
int main()
{
    int t;
    long long int n,x,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        x=n;
        if(n%2==0)
            n=(n-2)/2;
        else
            n=(n-1)/2;

        s=(n*n)%x;
        printf("n= %lld  %lld\n",n,s);

    }
    return 0;
}
