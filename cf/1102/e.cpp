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

ll power(ll x,  ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


int main()
{
  ll n; cin>>n;
  ll a[n+1];
  ll lt[200100];
  ll rt[200100];
  ll bl[200100];

  rep(i, 200100) lt[i] = n+2 , rt[i] = -2, bl[i] =0;
  rep(i, n) cin>>a[i] ,bl[a[i]] = 1,  lt[a[i]] = min(lt[a[i]] , (ll)i), rt[a[i]] = max(rt[a[i]] , (ll)i);

  // rep(i, 10) std::cout <<bl[i]<<" "<< lt[i]<<" "<<rt[i] << '\n';

  vector<pll> v;
  rep(i, 200100)
  {
    if(bl[i]==1)
    {
      v.pb(mp(lt[i], rt[i]));
    }
  }

  stack<pll> s;
  // std::cout << v.size() << '\n';
  sort(v.begin(), v.end());

  // rep(i, v.size()) std::cout << v[i].f<<" "<< v[i].s<< '\n';

  rep(i, v.size())
  {
    if(s.size() == 0) s.push(v[i]);
    else
    {
      pll top = s.top();
      if(top.s >= v[i].f)
      {
        // std::cout << "here" << '\n';
      top.s = v[i].s;
      s.pop();
      s.push(top);
      }
      else
      {
        s.push(v[i]);
      }

    }

  }
  // std::cout << s.size() << '\n';
  std::cout << power(2, s.size()-1, 998244353) << '\n';
  return 0;
}
