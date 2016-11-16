#include<map>
#include<stdio.h>
#include<iostream>
 
using namespace std;
 
map <int , long long> h;
 
long long f(int n) //precondition -> h.clear() 
{
  if (n == 0) return 0; //base
 
  long long r = h[n];
 
  if (r == 0) 
  {
    r = f(n/2)+f(n/3)+f(n/4);
    if (n > r)
    	h[n]= n;
    else
    	h[n] = r;
    return h[n];
  }
 
  return r;
}

int main()
{
	unsigned int n;
	
	while(scanf("%ld",&n) != EOF)
	{
		printf("%u",f(n));
	}
	
	return 0;
}
