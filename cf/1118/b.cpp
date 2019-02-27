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
ll ar[200010];
ll pre[200010][2];
int main()
{
	fastio;
	cin>>n;
	repn(i, n) cin>>ar[i], pre[i][0] = pre[i-1][0] , pre[i][1] = pre[i-1][1] , pre[i][i%2] += ar[i];
	ll ans = 0;
	repn(i, n)
	{
		ll tempeven = pre[i-1][0] + (pre[n][1] - pre[i][1]);
		ll tempodd = pre[i-1][1] + (pre[n][0] - pre[i][0]);
		if( tempodd == tempeven  ) ans++;
	}
	print(ans);
	return 0;
}
