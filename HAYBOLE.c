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
 	printf("Values %d x = %d\n",sum,x);
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
      //     update(i, a[i]);
     }*/
    
	 printf("sum of first 10 elements is %d\n", query(10));
     printf("sum of all elements in range [2, 7] is %d\n",query(7) - query(2-1));
  /*  update(7,1);
    update(8,1);
    update(9,1);*/
    printf("sum of first 10 elements is %d\n", query(10));
    
         for(i = 1; i <= n; i++)
     {
           printf("%d\n",  BIT[i]);
           
     }
	//update(5,1);
	ran_update(5,5,1);
	ran_update(2,4,1);
	ran_update(4,6,1);
	ran_update(3,5,1);
//	update(7,1);
	printf("sum of first 9 elements is %d\n", query(4));
//	printf("sum of all elements in range [7, 9] is %d\n",query(9) - query(7-1));
    
    
         for(i = 1; i <= n; i++)
     {
           printf("%d Query %dth value from BIT = %d\n",  BIT[i],i,query(i));
           
     }
	 return 0;
}
