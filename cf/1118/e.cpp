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


ll n, k;
int main()
{
	fastio;
	cin>>n>>k;
	ll mx = k*(k-1);

	if(n> mx)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;

	vector<pll> ans;

	ll idx=1;
	repn(gap, k-1)
	{
			if(ans.size() >=n) break;
		for(int i = 1; (i+gap) <=k ; i++)
		{
			ans.pb(mp(i, i+gap));
			// cout<<start<<" "<<(start+gap)<<endl;
			if(ans.size() >=n) break;

		}
			if(ans.size() >=n) break;
		for(int i =k ; i-gap >=1; i--)
		{
			ans.pb(mp(i, i-gap));
			// cout<<start<<" "<<(start+gap)<<endl;
			idx++;
			if(ans.size() >=n) break;

		}

	}
	rep(i, n) cout<<ans[i].f<<" "<<ans[i].s<<endl;
	return 0;
}
