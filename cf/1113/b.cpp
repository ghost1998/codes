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
	ll ar[n+2]; ll product = 1;
	ll sum=0;
	rep(i, n) cin>>ar[i] , product*=ar[i], sum+=ar[i] ;

	ll ans = sum;
	sort(ar, ar+n);

	rep(j, n-1) repn(i, 100)
	{
		if(ar[n-1 - j] %i ==0) ans = min(ans , sum - (ar[0] + ar[n-1 - j]) + (ar[0]*i + ar[n-1 -j]/i) );
	}


	print(ans);
	return 0;
}
