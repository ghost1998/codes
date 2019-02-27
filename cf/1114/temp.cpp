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

	ll q; cin>>q;
	while(q--)
	{
		string, s, t; cin>>s>>t;
		s.insert(0, 'a');
		t.insert(0, 'b');

		ll dp[s.size() +1][t.size() +1];
		rep(i, s.size() + 1) rep(j, t.size() + 1) dp[i][j] = 0;

		repn(i, s.size() -1) repn(j, t.size() -1)
		{
			dp[i][j] = ma
		}
	}
	return 0;
}
