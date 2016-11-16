/*int KS_combo(n,M)
{
	printf("%d    %d\n",n,M);
	
	if (M==0)
	return 1;
	if(n<0)
	return 0;
	if(arr[n]>M)
		return KS(n-1,M);
	else
		return KS(n-1,M)+KS(n-2,M-arr[n]);
}*/

int main()
{
	

int a[]={1,2,3};int i;
int n=sizeof(a)/sizeof(a[0]);
for(i=1; i<1<<n; i++)
{
    int temp=i;
    int j=0;
    while(temp)
    {
        if (temp&1) // if jth bit is set print a[j]
        {
            printf("%d ",a[j]);
        }
        temp >>= 1;
        j++;
    }
    printf("\n");
}


unsigned long long int k=56;
printf("%lld\n",1<<k);

return 0;
}
