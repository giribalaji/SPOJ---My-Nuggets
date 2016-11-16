#include<stdio.h>
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        
        long long t1= ((n-1)*n/2)%1000007;
        long long t2=(2*(n*(n+1))/2%1000007);
        printf("%lld\n",t1+t2);   
    }
    return 0;
}
