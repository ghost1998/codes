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
	ll ans=0;
	ll b, k; cin>>b>>k;
	ll ar[k+2];
	rep(i, k) cin>>ar[i];

	if(b%2 == 0)
	{
		ans = (ar[k-1]%2==0) ? 0 : 1;
	}
	else
	{
		ll count = 0;
		rep(i, k) if(ar[i]%2 == 1) count++;
		ans = (count%2==0) ? 0 : 1;
	}
	if(ans==1) cout<<"odd"<<endl;
	else cout<<"even"<<endl;
	return 0;
}
