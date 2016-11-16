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

int firstOccurrence_rec(int A[], int left, int right, int item) {
    
	
	if(left<=right)
	{
	
	int mid;
    
        mid = left + (right - left) / 2;
       
	   
	    if (A[mid] < item) 
            return firstOccurrence_rec(A, mid+1, right,  item);
        else if (A[mid] > item)
            return firstOccurrence_rec( A,  left,  mid-1,  item);
        else
        	{
        			return mid;	
        	}
	}
    return -1;
}

int main()
{
	
	int n,q,i;
	//int a[]={1,2,2,3,3,4,5,6,7,8};
	int a[100005];
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//printf("%d\n",firstOccurrence_rec(a,0,9,1));
	mergesort(a,0,n-1);
	while(q--)
	{
		int f;
		scanf("%d",&f);
		int ans=firstOccurrence_rec(a,0,n-1,f);
	//	printf("%d\n",ans);
		if(ans != -1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}	
	}
	
	return 0;
}
