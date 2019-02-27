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
string s;
ll a[1000];
ll dp[1000];
int main()
{
	fastio;

	cin>>n;
	cin>>s;
	repn(i, n) cin>>a[i], dp[i] = a[i];
	repn(i, n)
	{
		repn(j, i) dp[i] = max(dp[i], dp[j] + dp[i-j]);
	}
	return 0;
}


X = 3
(0, 0) : (0, 0) - (3, 3)
(0, 1) : (0, 3) - (3, 6)