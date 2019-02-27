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


int main()
{
  ll n, k; cin>>n>>k;
  ll temp;
  ll cnt[6000];
  ll ar[n+2];
  rep(i, 6000) cnt[i] = 0;
  rep(i, n) cin>>temp, ar[i] = temp,  cnt[temp]++;

  ll mx=-1, dt=0;
  rep(i, 6000) mx = max(mx, cnt[i]);
  rep(i, 6000) if(cnt[i] >0) dt++;
  // std::cout << mx<<" "<<k<< '\n';
  if(mx> k || n<k)
  {
    std::cout << "NO" << '\n';
  }
  else
  {
    std::cout << "YES" << '\n';
    vector<ll> v[6000];
    ll ans[n+2];
    rep(i, n)
    {
      v[ar[i]].pb(i);
    }
    ll tmp = 0;
    rep(i, 6000)
    {
      if(v[i].size() >0)
      {
        // std::cout << v[i].size() << '\n';
        rep(j, v[i].size()) ans[v[i][j]] = 1 + tmp%k, tmp++;
      }
    }
    rep(i, n)
    {
      std::cout << ans[i] << ' ';
    }
    std::cout << '\n';


  }
  return 0;
}
