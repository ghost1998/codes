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
  string s; cin>>s;

  int dp[s.size() +2][5];
  rep(i, s.size()+2) rep(j, 5) dp[i][j] = 0;
  dp[0][0] = s[0]=='[' ? 1 : 0;
  for(int i = 1; i < s.size(); i ++)
  {
    rep(j, 5) dp[i][j] = dp[i-1][j];

    if(s[i] == '[')
    {
      rep(j, 5) dp[i][j] = dp[i-1][j];
      dp[i][0] = 1;
    }
    else if(s[i] == ':')
    {
      rep(j, 5) dp[i][j] = dp[i-1][j];
      if(dp[i-1][0] > 0) dp[i][1] = max(dp[i][1],1 +  dp[i-1][0]);
      if(dp[i-1][1] > 0) dp[i][3] = max(dp[i][3], 1 + dp[i-1][2]);
      if(dp[i-1][1] > 0) dp[i][3] = max(dp[i][3], 1 + dp[i-1][1]);
    }
    else if(s[i] == '|')
    {
      rep(j, 5) dp[i][j] = dp[i-1][j];
      if(dp[i-1][1] > 0) dp[i][2] = max(dp[i][2], 1 + dp[i-1][1]);
      if(dp[i-1][2] > 0) dp[i][2] = max(dp[i][2], 1 + dp[i-1][2]);
    }

    else if(s[i] == ']')
    {
      rep(j, 5) dp[i][j] = dp[i-1][j];
      if(dp[i-1][3] > 0) dp[i][4] = max(dp[i][4], 1 + dp[i-1][3]);
    }
  }
  // std::cout << dp[s.size()-1][4] << '\n';
  // rep(i, s.size())
  // {
  //   std::cout << s[i] << "  :  ";
  //   rep(j, 5) std::cout << dp[i][j] << ' ';
  //   std::cout  << '\n';
  // }

  if(dp[s.size()-1][4] == 0) std::cout << -1 << '\n';
  else std::cout << dp[s.size()-1][4] << '\n';
  return 0;
}


// 0 : [
// 1 : :
// 2 : |
// 3 : :
// 4 : ]
