#include<stdio.h>
#include<stdlib.h>
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
 	//printf("Values %d x = %d\n",sum,x);
	  }
	 return sum;
}

int main()
{
int t;

     int k,i,u1,u2,q,q1;
	 scanf("%d", &t);

while(t--)
{

	 scanf("%d %d", &n,&k);
   for(i=0;i<k;i++)
{
	scanf("%d %d",&u1,&u2);
	ran_update(u1,u2,1);
}

 scanf("%d", &q);
    
         for(i = 1; i <= n; i++)
     {
          
           a[i]=query(i);
           
     }
     
         for(i = 0; i < q; i++)
     {
          
           scanf("%d", &q1);
		   printf(" Query %dth value\n",query(q1));
           
     }
     
//memset(BIT,0,sizeof(BIT));
}
	 return 0;
}
