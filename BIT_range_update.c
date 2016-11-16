#include<stdio.h>
int BIT[1000], a[1000], n;
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
 	//printf("Values %d x = %d\n",sum,x);
	  }
	 return sum;
}

int main()
{
     scanf("%d", &n);
     int i;
/*     for(i = 1; i <= n; i++)
     {
           scanf("%d", &a[i]);
           update(i, a[i]);
     }*/

	ran_update(2,4,26);
//	update(7,1);
//	printf("Value of first 8 elements is %d\n", query(8));
	ran_update(4,8,80);
	ran_update(4,5,20);
	ran_update(5,7,14);
//	printf("Value of first 4 elements is %d\n", query(4));
	
	
	//printf("sum of all elements in range [7, 9] is %d\n",query(9) - query(7-1));
    
    
        for(i = 1; i <= n; i++)
     {
           printf("%d\n",BIT[i]);
           printf("Query value for %d is:%d\n",i,query(i));
     }
//	scanf("%d",&n);
	 return 0;
}
