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


map< ll, map< ll, ll > > m;
ll ans=1;

ll ar[200012];
vector<ll> adj[200012];
vector<ll> vis(200012, 0);
ll start = 1;
ll n;

void fill(int idx)
{
  map<ll, ll> ans ;

  ll temp = ar[idx];
  while(temp%2 == 0) ans[2] = 1,  temp = temp/2;

  for(int i = 3; i <= sqrt(temp); i = i+2)
  {
    while(temp%i == 0) ans[i] = 1,  temp = temp/i;
  }

  if(temp > 1) ans[temp] = 1;

  m[idx] = ans;
  // std::cout << m[idx].size() << '\n';
  return ;
}

void dfs(int start, int par=0)
{

  if(vis[start] == 1) return ;
  vis[start] = 1;

  for(auto j : adj[start]) dfs(j, start);

  // std::cout << "-------" << '\n';
  // std::cout << start << '\n';
  // std::cout << m[start].size() << '\n';
  for(auto i : m[start])
  {
    vector<ll> tmp;
    for(auto j : adj[start])
    {
      if(j !=par && m[j].find(i.f) != m[j].end())  tmp.pb(m[j][i.f ]);
    }

    // for(auto k : tmp) std::cout << k << ' ';
    // std::cout << '\n';
    sort(tmp.begin(), tmp.end());
    if(tmp.size() >0) m[start][i.f] = max(m[start][i.f], 1 + tmp[tmp.size()-1]) , ans = max(ans, m[start][i.f]);
    //
    if(tmp.size()>=2) ans = max(ans , 1 + tmp[tmp.size()-1]+ tmp[tmp.size()-2]);
  }
  return;
}

int main()
{
   cin>>n;
   int not_pos = 1;
  repn(i, n) cin>>ar[i], fill(i) ;

  repn(i, n) if(ar[i]!=1) not_pos=0;

  rep(i, n-1)
  {
    ll t1, t2; cin>>t1>>t2;
    adj[t1].pb(t2);
    adj[t2].pb(t1);
  }

  if(not_pos)
  {
    std::cout << 0 << '\n';
    return 0;
  }

  dfs(1);
  std::cout << ans << '\n';
  return 0;
}
