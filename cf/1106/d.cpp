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



void merge(vll &a, vll &b)
{
	
}
void dfs(ll start, vector<ll> &ans)
{
	if(vis[start] ==1) return;

	vis[start] = 1;
	ans.pb(start);
	// print(start);
	rep(i, adj[start])
	{
		if(vis[adj[start][i]] ==1) continue;

		vll temp;
		dfs(adj[start][i], temp);
		merge(ans, temp);
	}
	return ;
}


ll m, n;
vector<ll> adj[100010];
ll vis[100010];
int main()
{
	fastio;
	cin>>n>>m;
	ll a, b;
	rep(i, m)
	{
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<ll> ans;
	dfs(1, ans)
	return 0;
}
