#include<stdio.h>

void merge(int a[],int left,int mid,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;
	int k=left;
	
	int sl[n1];
	int sr[n2];
	int i=0,j=0;
	for(;i<n1;i++)
	{
		sl[i]=a[left+i];
	}
	
	for(;j<n2;j++)
	{
		sr[j]=a[mid+1+j];
	}
	
	 i=0,j=0;
	while(i<n1 && j < n2)
	{
		if(sl[i]<=sr[j])
		{
			a[k]=sl[i];
			k++,i++;
		}
		else
		{
			a[k]=sr[j];
			k++,j++;
			//count=count+(n1-i);
		}
	}
	
	
	//copy remaining elements
	
	while(i<n1)
	{
		a[k++]=sl[i++];
	}
	
	while (j<n2)
	{
		a[k++]=sr[j++];
	}
	
	
}



void mergesort(int a[],int left,int right)
{
	int mid=left+((right-left)/2);
	if(left<right)
	{
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
		
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
         int t;
        long int n;
        scanf("%d",&t);
        
        while(t--)
        {
               int w,h,n,i;
               scanf("%d %d %d",&w,&h,&n);
               int wa[n],ha[n],dw[n+1],dh[n+1];
               for(i=0;i<n;i++)
               {
               	scanf("%d %d",&wa[i],&ha[i]);
               }
               mergesort(wa,0,n-1);
               mergesort(ha,0,n-1);
               
               dw[0]=wa[0]-1;
				dw[n]=w-wa[n-1];
				
				dh[0]=ha[0]-1;
				dh[n]=h-ha[n-1];
				
			   for(i=1;i<n;i++)
			   {
			   	dw[i]=wa[i]-wa[i-1]-1;
			   }
               
				for(i=1;i<n;i++)
			   {
			   	dh[i]=ha[i]-ha[i-1]-1;
			   }
				
				
				 int max_w=0,max_h=0;
				 for(i=0;i<=n;i++)
				 {
				 	if(dw[i]>max_w)
				 		max_w=dw[i];
				 }
				 
				 for(i=0;i<=n;i++)
				 {
				 	if(dh[i]>max_h)
				 		max_h=dh[i];
				 }
				
				//     printArray(a,n);

				printf("%d\n",max_w*max_h);
                        }
        return 0;
}
