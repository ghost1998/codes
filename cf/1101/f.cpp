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

ll n, m;
ll city[402];
ll truck[250010][4];
ll idx[250010];

int check(ll i, ll val)
{
  ll s = truck[i][0],f = truck[i][1],c = truck[i][2],r = truck[i][3];

  ll cur = val;

  for(ll j = s; j<f; j++)
  {
    if((city[j+1] - city[j]) * c > val) return 0;

    if ( (city[j+1] - city[j]) * c > cur)
    {
      if(r<=0) return 0;
      r--;
      cur = val;
    }
    cur -= (city[j+1] - city[j])*c;
  }
  return 1;

}

ll search(ll i, ll lo, ll hi)
{
  if(lo == hi) return lo;
  ll mid = lo + (hi-lo)/2;
  if(check(i, mid)) return search(i, lo, mid);
  else return search(i, mid+1, hi);
}
int main()
{
  cin>>n>>m;
  repn(i, n) cin>>city[i];
  repn(i, m) cin>>truck[i][0]>>truck[i][1]>>truck[i][2]>>truck[i][3];
  repn(i, m) idx[i] = i;
  // rep(i, m) std::cout << idx[i] << ' ';
  // std::cout  << '\n';
  random_shuffle(idx+1, idx+1+m);
  // rep(i, m) std::cout << idx[i] << ' ';
  // std::cout  << '\n';

  ll cur = 0;

  // std::cout <<  check(3, 13) << '\n';;

  repn(i, m)
  {
    if(check(idx[i], cur)) continue;

    cur = search(idx[i], cur, LLONG_MAX);

    // std::cout << search(idx[i], 0, 100000) << '\n';
  }

  std::cout << cur << '\n';





  return 0;
}
