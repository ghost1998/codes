#include <bits/stdc++.h>
using namespace std;

long long mini(long long a, long long b, long long c, long long d)
{

  return min(min(a, b), min(c,d));
}
int main()
{
  long long n; cin>>n;
  string s; cin>>s;
  long long ar[n+3];
  for(long long i = 1; i<=n;i++) cin>>ar[i];
  long long dp[n+3][5];
  dp[0][0] = 0;dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 100000;

  for(long long i = 1; i<=n;i++)
  {
    if(s[i-1] == 'h')
    {
      dp[i][0] = dp[i-1][0] + ar[i];
      dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3];
      dp[i][4] = dp[i-1][4];
    }
    else if(s[i-1] == 'a')
    {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1] + ar[i];
      dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
      dp[i][3] = dp[i-1][3];
      dp[i][4] = dp[i-1][4];
    }
    else if(s[i-1] == 'r')
    {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2] + ar[i];
      dp[i][3] = min(dp[i-1][2],  dp[i-1][3]);
      dp[i][4] = dp[i-1][4];
    }
    else if(s[i-1] == 'd')
    {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3] + ar[i];
      dp[i][4] = min( dp[i-1][3],  dp[i-1][4]);
    }
    else
    {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3];
      dp[i][4] = dp[i-1][4];
    }
    // std::cout << dp[i][0] <<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<dp[i][4] << '\n';

  }
  std::cout << mini(dp[n][0],dp[n][1], dp[n][2], dp[n][3]) << '\n';

  return 0;
}
