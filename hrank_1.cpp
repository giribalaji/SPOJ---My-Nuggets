#include <bits/stdc++.h>

#define stream istringstream
#define rep(i,n) for(i64 i=0; i<(i64)n; i++)
#define repv(i,n) for(i64 i=n-1; i>=0; i--)
#define repl(i,n) for(i64 i=1; i<=(i64)n; i++)
#define replv(i,n) for(i64 i=n; i>=1; i--)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (i64)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<i64,i64>
#define pmp make_pair
#define uu first
#define vv second
using namespace std;


int coin[]= {1,2,5,10,20,50,100 };
int call(int i,int n)
{
    if(n<0)return 0;
    if(n==0) return 1;
    if(i==7) return 0;
    int ans=0;


    ans+=call(i+1,n-coin[i])+call(i+1,n);

    return ans;
}
int main()
{
//  READ("in");
    int n;
    cin>>n;
    assert(n<=250);
    assert(n>=1);
    cout<<call(0,n)<<endl;
      return 0;
}
