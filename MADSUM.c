#include<stdio.h>
#include<math.h>
long long int powe(long long int base, int pow){
//Special Cases:
    if (pow == 0) {return 1;}
    if (pow < 0)   {return 0;}  //No negative power is an integer
 
    long long int result=1,i;
         for( i=0;i<pow;i++){
               result *= base;
         }
    return result;
}

long long int fun(long long int k)
{
long long int n=k/2;
	if(k%2)
	{
		n++;
	}
//	printf("%d\n",n);
	//return (n*(1+k))/2;
	return n;

}

int main()
{
	long long int a,b;
//	while(1)
//	{
	
	scanf("%lld %lld",&a,&b);

	printf("%lld\n",powe(fun(b),2)-powe(fun(a),2));
//}
	return 0;
}
