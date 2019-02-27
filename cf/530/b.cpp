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
  ll ans=-1;
  int a[] = {0, 2,3,4,4,5};
  if(n<=5)
  {
    ans = a[n];
    std::cout << ans << '\n';
    return 0;
  }

  ll i = 0;
  while(i*i <= n) i++; i--;

  if(n == i*i ) ans = 2*i;
  else if(n <= i*i + i) ans = 2*i + 1;
  else ans = 2*i + 2;
  std::cout << ans << '\n';
  return 0;
}
