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


ll n, m;
ll ar[200010];

int isValid(ll value)
{
	ll ans=0;
	rep(i, n)
	{
		// print((ar[i] - (i/value)));
		ans+= max( (ll)0, (ar[i] - (i/value)));
	}
	// print(ans);
	if(ans >= m ) return 1;
	else return 0;
}

ll bsearch(ll lo, ll hi)
{
	// cout<<lo<<" "<<hi<<endl;
	if(lo == hi) return lo;

	ll mid = lo + (hi - lo)/2 ;

	if(isValid(mid) == 1) return bsearch(lo, mid);
	else return bsearch(mid+1, hi);
}
int main()
{
	fastio;
	cin>>n>>m;
	ll sum = 0;
	rep(i,n) cin>>ar[i] , sum+=ar[i];
	sort(ar, ar+n, greater<int>());
	if(sum < m)
	{
		ll ans = -1;
		print(ans);
		return 0;
	}
	// printarray(ar, 0, n-1);

	ll ans = bsearch((ll)1, sum);
	print(ans);
	// print(isValid(2));
	return 0;
}
