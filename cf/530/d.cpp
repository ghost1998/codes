#include <bits/stdc++.h>
using namespace std;

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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())


void dfs(ll start, ll &ans, vector<ll> &val, vector<ll> adj[], ll cur, int &possible)
{
  // std::cout << "---" << '\n';
  // std::cout << start << '\n';
  // std::cout << adj[start].size() << '\n';
  if(possible == 0) return ;

  // leaf
  if(adj[start].size() == 0)
  {
    if(val[start] == -1 ) return;

    if(val[start] < cur) {possible = 0; return;};

    ans += (val[start]-cur) ;
    cur = val[start];
    return;
  }

  //not a leaf
  if(val[start] == -1 )
  {

  }

  else
  {
    // std::cout << "h" << '\n';
    if(val[start] < cur) {possible = 0;return;};
    ans += (val[start]-cur);
    cur = val[start];
  }


  rep(i, adj[start].size())
  {
    dfs(adj[start][i], ans, val, adj, cur, possible);
  }

  return ;
}

int main()
{
  ll n, temp; cin>>n;
  vector<ll> adj[n+2];
  vector<ll> val(n+2, 0);
  rep(i, n-1)
  {
    cin>>temp;
    adj[temp].pb(i+2);
  }
  rep(i, n)
  {
    cin>> val[i+1];
  }

  ll ans = 0;
  int possible = 1;
  ll cur = 0;
  dfs(1, ans, val, adj, cur, possible);
  if(possible == 0) ans = -1;
  std::cout << ans << '\n';
  return 0;
}
