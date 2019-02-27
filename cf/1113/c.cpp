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
ll ar[300010];
ll pre[300010];
ll pas[300010];
ll ans;
ll hash[10000000][3];
int main()
{
	fastio;
	cin>>n;
	pre[0] = 0;
	repn(i, n) cin>>ar[i] , pre[i] = pre[i-1]^ ar[i];

	rep(i, 10000000) rep(j, 3) hash[i][j] = -1;

	repn(i, n)
	{
		if(i%2 == 0)
		{
			if(hash[pre[i]][0] == -1)
			{

			}
			else
			{
				
			}
		}
	}
	print(ans);
	return 0;
}
