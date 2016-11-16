int N; // read-only number of wines in the beginning

int p[2005]; // read-only array of wine prices

int dp[2005][2005];
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))
int profit(int be, int en,int year) {


  year=year+1;
  if (be > en)

    return 0;

if(dp[be][en]==0)
  // (en-be+1) is the number of unsold wines

  //int year = N - (en-be+1) + 1; // as in the description above
{
  return dp[be][en]=MAX(

    profit(be+1, en,year) + year * p[be],

    profit(be, en-1,year) + year * p[en]);
}

else
{
	return dp[be][en];
}


}


int main()
{
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)
	{
	scanf("%d",&p[i]);	
	}
	int k=profit(0,N-1,0);
	printf("%d",k);

}
