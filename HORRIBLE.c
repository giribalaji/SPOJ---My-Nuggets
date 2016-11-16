#include<stdio.h>
#include<stdlib.h>
int BIT[1000005],  n;
void update(int x, int val)
{
      for(; x <= n; x += x&-x)
      {
      
        BIT[x] += val;
  //printf("Values %d x = %d\n",BIT[x],x);
  }
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

     int k,i,u1,u2,v,q,q1,q2,j;
	 scanf("%d", &t);

while(t--)
{

	 scanf("%d %d",&n,&k);
   for(i=0;i<k;i++)
{

 scanf("%d", &q);

if(q==0)
{

	scanf("%d %d %d",&u1,&u2,&v);
printf("%d %d %d\n",u1,u2,v);
	ran_update(u1,u2,v);

}


else
     {
          
           scanf("%d %d",&q1,&q2);
           if(q1<q2)
           {
           
		   printf("%d ",query(q1-1));
		   printf("%d\n",query(q2));
	}
	else
	{
		printf("%d ",query(q1));
		   printf("%d\n",query(q2-1));
	}
           
     }
        for(j = 1; j <= n; j++)
     {
           printf("%d\n",  BIT[j]);
           
     }

}
memset(BIT,0,sizeof(BIT));
}


	 return 0;
}
