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

ll dp[500];
ll total;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k; cin>>n>>k;
  ll ar[n+1];
  rep(i, n) cin>>ar[i];

  rep(i, n) dp[i%k] += ar[i], total+= ar[i];

  ll ans = 0;

  rep(i, k) ans = max(ans, abs(total - dp[i]));
  std::cout << ans << '\n';
  return 0;
}
