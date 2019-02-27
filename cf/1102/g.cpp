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
  ll n, m; cin>>n>>m;
  ll ar[n][m];
  rep(i, n) rep(j, m) cin>>ar[i][j];
  ll dp[1<<(n+1)];
  rep(i, 1<<(n+1)) dp[i] = 1000;
  dp[0] = 0;

  rep(i, 1<<(n+1)-1)
  {
    rep(j,17)
    {
      if(i && 1<<j == 0) //jth bit not set
      {

        dp[i | 1<<j ] = min(dp[i | 1<<j ] , n1);
      }
    }
  }
  return 0;
}
