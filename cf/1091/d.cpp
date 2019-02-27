#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main()
{
  long long n; cin>>n;
  long long fac[n+5];
  fac[0] = 1;
  for(int i=1; i <n+3; i++) fac[i] = (i*fac[i-1])%mod;
  long long dp[n+5];
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 9;
  for(int i = 4; i<n+2; i++) dp[i] = (i* ((fac[i-1] + dp[i-1] -1)%mod))%mod;
  std::cout <<dp[n] << '\n';
  return 0;
}

//
// f(n) = n*((n-1)! + f(n-1)-1)
// dp[n] = n* (fac[n-1] + dp[n-1] -1)
// dp[n] = (n* ((fac[n-1] + dp[n-1] -1)%mod))%mod;
