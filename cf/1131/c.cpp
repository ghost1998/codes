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
	ll ar[n+1]; rep(i, n) cin>>ar[i];
	ll ans[n+1];
	sort(ar, ar+n);
	int idx =0;
	for(int i =0; i <n; i+=2)
	{
		ans[idx] = ar[i];idx++;
	}

	ll temp = n-1 - ((n-1)%2==0 ?1:0);
	for(int i= temp; i>=0; i-=2)
	{
		ans[idx] = ar[i];idx++;
	}

	rep(i, n) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
