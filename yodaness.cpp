#include<stdio.h>
#include<iostream>
#include <string>
#include<map>

using namespace std;
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
         int a[200010];int t;
        long int n;
        scanf("%d",&t);
        
        while(t--)
        {
               long int i,j,tmp=1;
			    scanf("%ld",&n);
                string s[n+1],temp;
                for(i=0;i<n;i++)
                {
                	cin>>s[i];
                }
				
				map<string,int>mp;
				                  
			     
			     for(i=0;i<n;i++)
                {
                        cin>>temp;
                        mp[temp]=tmp;
                        tmp++;
               }
   
            	for(i=0;i<n;i++)
            	{
            		a[i]=mp[s[i]];
            	}
                count=0;
				mergesort(a,0,n-1);
				printf("%lld\n",count);
				//     printArray(a,n);

                        }
        return 0;
}
