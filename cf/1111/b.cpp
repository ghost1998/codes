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
#define print(x) cout<<setprecision(9) <<x<<endl;
#define printarray(a, start, end) for(int i=start; i<=end; i++) cout<<a[i]<<" "; cout<<endl;



int main()
{
	fastio;
	ll n, k, m; cin>>n>>k>>m;
	ll ar[n+2];
	ll sum = 0;
	rep(i, n) cin>>ar[i], sum+=ar[i];
	sort(ar, ar+n);
	// if(m>=n)

	// ll x = (m-n)/(k-1);
	// ll sum = 0;
	// rep(i, x) sum+=ar[n-1-i];

	// // sum += (m-n)%(k-1);
	// sum+= (x*k);
	// print(sum);
	// print(x);
	// double ans = (1.0 * (double)sum) / (1.0 * (double)x);
	// print(ans);

	ll mx=0;
	rep(i, n) mx = max(mx, ar[i]);
	ll count = 0;
	rep(i, n) if(ar[i] == mx) count++;

	// ll sum = count*mx;

	
	rep(i, min(n-count , m)) sum-=ar[i];
	sum+= min((m-min(n-count , m)) , k* (n-min(n-count , m)));
	// print(sum);
	double ans = (1.0 * double(sum))/ (1.0 * double(n - min(n-count , m)));
	cout<<setprecision(12) <<ans<<endl;
	return 0;
}
