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


vector<ll> rt[100010];
vector<ll> le[100010];
ll ar[100010];
ll a1[100010];
ll a2[100010];
ll pre[100010];
ll suf[100010];
ll r,l;
int main()
{
	fastio;
	ll n, m;
	cin>>n>>m;
	repn(i, n) cin>> ar[i], a1[i] = a2[i] = ar[i];
	repn(i, m) cin>>l>>r, cout<<r<<" "<<l<<endl, rt[r].pb(l) , le[l].pb(r);
	print(rt[3].size())
	pre[0] = 10000000;
	suf[n+1] = 10000000;

	printarray(a1, 0, n+1);
	printarray(a2, 0, n+1);

	repn(i, n)
	{
		pre[i] = pre[i-1];
		rep(j, rt[i].size()) for(ll k =i; k>=rt[i][j];k--) a1[k]--, pre[i] = min(pre[i], a1[k]);
	}

	for(ll i=n; i>=1; i--)
	{
		suf[i] = suf[i+1];
		rep(j, le[i].size()) for(ll k = i; k<=le[i][j]; k++) a2[k]--, suf[i] = min(suf[i], a2[k]);
	}

	printarray(a1, 0, n+1);
	printarray(a2, 0, n+1);

	ll ans = 0;
	
	repn(i, n) ans = max(ans, abs(ar[i] - min(pre[i-1] , suf[i+1])));
	print(ans);
	printarray(pre, 0, n+1);
	printarray(suf, 0, n+1);
	return 0;
}
