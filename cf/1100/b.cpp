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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

ll cnts[100010];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m; cin>>n>>m;

  ll count = 0;
  rep(i, m)
  {
    ll dif ; cin>>dif;
    cnts[dif]++;
    if(cnts[dif] == 1) count++;

    if(count == n)
    {
      std::cout << 1 ;
      rep(j, m)
      {
        cnts[j]--;
        if(cnts[j]==0) count--;
      }
    }
    else std::cout << 0;
  }
  std::cout << '\n';

  return 0;

}
