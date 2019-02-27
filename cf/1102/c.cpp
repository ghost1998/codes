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
  ll n, x, y, ans; cin>>n>>x>>y;
  ll a[n+1];
  rep(i, n) cin>>a[i];
  if(x>y) ans = n;
  else
  {
    ll lesser = 0;
    rep(i, n) if(a[i] <= x) lesser++;
    ans = (lesser+1)/2;
  }
  std::cout << ans << '\n';
  return 0;
}
