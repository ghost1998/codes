#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


typedef long long ll;
typedef long int li;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double ld;

#define mp make_pair
#define f first
#define s second

#define pu push
#define pb push_back

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define print(x) cout<<x<<endl;
#define printarray(a, start, end) for(int i=start; i<=end; i++) cout<<a[i]<<" "; cout<<endl;

ll n, l,r;
ll r0,r1,r2;
ll dp[200010][3];
ll mod = 1000000007;
int main()
{
	fastio;
	cin>>n>>l>>r;
	r0 = r/3 - (l-1)/3;
	r1 = (r+2)/3 - (l-1+2)/3;
	r2 = (r+1)/3 - (l-1+1)/3; 
	dp[0][0] = 1;
	// dp[0][0] = 1;
	// dp[0][0] = 1;
	repn(i, n)
	{
		dp[i][0] = ((dp[i-1][0] * r0)%mod + (dp[i-1][1] * r2)%mod + (dp[i-1][2] * r1)%mod) % mod;
		dp[i][1] = ((dp[i-1][0] * r1)%mod + (dp[i-1][1] * r0)%mod + (dp[i-1][2] * r2)%mod) % mod;
		dp[i][2] = ((dp[i-1][0] * r2)%mod + (dp[i-1][1] * r1)%mod + (dp[i-1][2] * r0)%mod) % mod;
	}

	// cout<<"here"<<endl;
	// print(r0);
	// print(r1);
	// print(r2);

	print(dp[n][0]);

	return 0;
}
