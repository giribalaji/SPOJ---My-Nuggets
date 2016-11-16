#include<stdio.h>
#include<stack>

using namespace std;

stack<char>s;

int main()
{
	int t;
	scanf("%d",&t);
	char *str="umank";
	while(t--)
	{
	long long int rem,n;
	scanf("%lld",&n);
	
		while(n>0)
		{
			rem=n%5;
			if(rem==0)
				n=(n/5)-1;
			else
				n=n/5;
				
			s.push(str[rem]);
			//printf("%c",str[rem]);
		}
		while(!s.empty())
		{
			printf("%c",s.top());
			s.pop();
		}
		
		printf("\n");
	}
	
	return 0;
}
