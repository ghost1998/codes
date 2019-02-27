#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int n; cin>>n;
  long int ar[n+1];
  for(int i = 0 ; i < n ; i ++) cin>>ar[i];

  long int ans = 10000000000;
  long int temp = ans;
  long int sum = 0;
  for(int i = 0 ; i < n ; i++)
  {
    temp = 0 ;
    for(int j = 0 ; j < n ; j++)
    {
      if(j<=i) temp += ar[j]*(2*i);
      if(j>i) temp += ar[j] * (2*j);
    }
    ans = min(ans, temp);
  }

  std::cout << 2*ans << '\n';
  return 0;
}
