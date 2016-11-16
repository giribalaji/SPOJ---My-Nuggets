int firstOccurrence(int A[], int left, int right, int item) {
    int mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (A[mid] >= item) 
            right = mid;
        else
            left = mid;
    }
    return right;
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
        		if(mid>0&&A[mid-1]==item)
        			return firstOccurrence_rec( A,  left,  mid-1,  item);
				else
					return mid;	
        	}
}
    return -1;
}

int main()
{
	int a[]={1,2,2,3,3,4,5,6,7,8};
	printf("%d\n",firstOccurrence(a,0,9,9));
	printf("%d\n",firstOccurrence_rec(a,0,9,1));
	return 0;
}
