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
  ll mxlimit = 200010;

  ll t; cin>>t;
  ll l,r;

  while(t--)
  {
    ll n; cin>>n;

    vector<ll> ans(n+2, 0);
    vector< pair<ll, pair<ll, ll> >  > v;

    rep(i, n)
    {
      cin>>l>>r;
      v.pb(mp(l, mp(r,(ll)i)));
    }

    sort(v.begin(), v.end());

    stack< pair<ll, pair<ll, ll> >  > st;

    // rep(i, v.size()) std::cout << v[i].f <<" "<<v[i].s.f<<" "<<v[i].s.s << '\n';

    rep(i, v.size())
    {
      if(st.size() ==0) st.push(v[i]), ans[v[i].s.s] = 1;
      else
      {
        pair<ll, pair<ll, ll> > top = st.top();
        // std::cout << top.f <<" "<<top.s.f<<" "<<top.s.s << '\n';

        if(top.s.f < v[i].f)
        {
          ans[v[i].s.s] = 3 - ans[top.s.s];
          st.push(v[i]);
        }
        else
        {
          ans[v[i].s.s] = ans[top.s.s];
          top.s.f = max(top.s.f , v[i].s.f);
          st.pop();
          st.push(top);
        }
      }
    }

    // rep(i, n+2) std::cout << i <<" : "<< ans[i] << '\n';
    int sec = 0;
    rep(i, n) {if(ans[i] == 2) {sec=1; break;}}
    if(sec)
    {
      rep(i, n) std::cout << ans[i] << ' ';
      std::cout  << '\n';
    }
    else std::cout << "-1" << '\n';

  }
  return 0;
}
