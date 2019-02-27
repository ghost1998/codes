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


ll n;
ll temp[10000000];
ll ar[1000000];
ll rev[1000000];
ll dp[6000][6000];
int main()
{
	fastio;
	cin>>n;
	rep(i, n) cin>>temp[i];
	vll v;
	rep(i , n)
	{
		if(v.size() == 0) v.pb(temp[i]);
		else
		{
			if(v[v.size() - 1] != temp[i]) v.pb(temp[i]);
		}
	}

	rep(i, v.size()) ar[i+1] = v[i] , rev[v.size() - i] = v[i] ;

	repn(i, v.size()) repn(j, v.size())
	{
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		if(ar[i] == rev[j]) dp[i][j] = max(dp[i][j] , 1 + dp[i-1][j-1]) ;
		// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	}

	ll ans = v.size() - 1;

	repn(i, v.size())
	{

		ans = min(ans, ((ll)v.size()-1- dp[i-1][v.size()-i]));
		// cout<<i-1<<" "<<v.size()-i<<endl;
	}

	// rep(i, v.size())
	// {
	// 	cout>>
	// }
	// print(v.size());
	print(ans);



	return 0;
}
