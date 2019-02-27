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



int main()
{
	fastio;

	ll n; cin>>n;
	ll mx = -1;
	ll maxcount=0;
	ll curcout = 0;
	ll ar[n+2]; rep(i, n) cin>>ar[i] , mx = max(mx, ar[i]);
	// print(mx); 

	if(ar[0] == mx) curcout = 1 , maxcount = 1;

	repn(i, n-1)
	{
		if(ar[i] == mx) curcout++, maxcount = max(maxcount, curcout);
		else curcout = 0;
	}

	print(maxcount);
	return 0;
}
