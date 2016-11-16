#include<stdio.h>
static long long int count;
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
			count=count+(n1-i);
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
        long int a[200010];int k;
        long int n,i,j,d;
        
                scanf("%ld %ld",&n,&k);
                //long int i,j,tmp;
				count=0;
                for(i=0;i<n;i++)
                {
                        scanf("%ld",&a[i]);
                
                                  }
                
				mergesort(a,0,n-1);
				count=0;
				
				for(i=0;i<n-1;i++)
				{
					for(j=i+1;j<n;j++)
					{
						d=a[j]-a[i];
						if(d<k)
							continue;
						else if(d==k)
							count++;
						else
							break;
					}
				}
				
				printf("%lld\n",count);
				//     printArray(a,n);

                        
        return 0;
}
