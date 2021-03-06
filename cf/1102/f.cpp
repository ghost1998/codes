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

  map<ll, pll> m;
  rep(i, n)
  {
    cin>>a[i];
    if(m.find(a[i]) == m.end())
    {
      m[a[i]] = mp((ll)i, (ll)i);
    }
    else
    {
      m[a[i]].f = min((ll)i, m[a[i]].f);
      m[a[i]].s = max((ll)i, m[a[i]].s);
    }
  }

  // std::cout << m.size() << '\n';
  stack<pll> s;
  vector<pll> v;
  for(map<ll, pll>::iterator it = m.begin(); it!=m.end(); it++)
  {
    v.pb(it->second);
  }
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
      top.s = max(top.s, v[i].s);
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
