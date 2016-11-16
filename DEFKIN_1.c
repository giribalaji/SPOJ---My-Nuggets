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
              int W,H,N,i,temp_x,temp_y;
  scanf("%d%d%d",&W,&H,&N);
  int X[N+1],Y[N+1];
  for(i=0;i<N;i++)
   scanf("%d%d",&X[i],&Y[i]);
  mergesort(X,0,N-1);
  mergesort(Y,0,N-1);
  X[N]=W+1;
  Y[N]=H+1;
  long long max_x,max_y;
  max_x=X[0];
  max_y=Y[0];
  for(i=1;i<=N;i++)
  {
   temp_x=X[i]-X[i-1];
   temp_y=Y[i]-Y[i-1];
   if(max_x<temp_x)
    max_x=temp_x;
   if(max_y<temp_y)
    max_y=temp_y;
  }

  printf("%lld\n", (max_y - 1) * (max_x - 1));
                        }
        return 0;
}
