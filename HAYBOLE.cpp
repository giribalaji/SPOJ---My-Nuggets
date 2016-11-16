
#include<map>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int BIT[1000005], a[1000005], n;
void update(int x, int val)
{
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}

void ran_update(int i,int j,int val)
{
	update(i,val);
	update(j+1,-val);
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
     {
     
        sum += BIT[x];
 	printf("Values %d x = %d\n",sum,x);
	  }
	 return sum;
}

int main()
{
     int k,i,u1,u2;
	 scanf("%d %d", &n,&k);
     //int i;
for(i=0;i<k;i++)
{
	scanf("%d %d",&u1,&u2);
	ran_update(u1,u2,1);
}

	//update(5,1);
//	ran_update(5,5,1);
	

//	printf("sum of first 9 elements is %d\n", query(4));

    
    
         for(i = 1; i <= n; i++)
     {
          // printf("%d Query %dth value from BIT = %d\n",  BIT[i],i,query(i));
           a[i]=query(i);
           printf(" Query %dth value  a[]= %d\n",i,a[i]);
     }
	sort(a+1,a+n+1);
	    for(i = 1; i <= n; i++)
     {
          // printf("%d Query %dth value from BIT = %d\n",  BIT[i],i,query(i));
          // a[i]=query(i);
           printf(" Query %dth value  a[]= %d\n",i,a[i]);
     }
	
	printf("%d %d\n",n/2,a[n/2+1]);
	
	 return 0;
}
