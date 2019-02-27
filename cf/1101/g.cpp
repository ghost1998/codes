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
  ll n; cin>>n;
  ll ar[n+1];
  ll pre[n+1];
  repn(i, n) cin>>ar[i];
  pre[0] = 0;
  repn(i, n) pre[i] = pre[i-1]^ar[i];
  if(pre[n] == 0)
  {
    std::cout << -1 << '\n';
    return 0;
  }

  int cur = 1;
  for(int idx = 30; idx>=0; idx--)
  {
    // std::cout << cur << '\n';
    for(int i = cur; i<=n; i++) if(pre[i]  & 1<<idx) {swap(pre[i], pre[cur]) ; break;}

    if(pre[cur] & 1<<idx)
    {
      // std::cout << "idx : "<<idx << '\n';
      repn(i, n)
      {
        if(cur == i) continue;
        if(pre[i] & 1<<idx) pre[i] ^= pre[cur];
      }
      cur++;
    }
  }

  
  ll ans = 0;
  // repn(i, n) std::cout << pre[i] << '\n';
  repn(i, n) if(pre[i] > 0) ans++;
  std::cout << ans << '\n';
  return 0;
}

//
// 6
// 5 3 2  6  4 1
