#include <bits/stdc++.h>
using namespace std;


int main()
{
  long int ix=1;
  long int t; cin>>t;
  while(t--)
  {
    long int n; cin>>n;
    vector<int> v(n, 0);
    vector<int> pre(n, 0);
    string temp; cin>>temp;
    for(int i=0; i<n;i++) v[i] = temp[i]- '0';
    // for(int i=0; i<n;i++) std::cout << v[i] << '\n';
    int sz = (n+1)/2;
    // std::cout << sz << '\n';
    pre[0] = v[0];
    int ans = 0;

    for(int i=1; i<n;i++)
    {
      pre[i] = v[i] + pre[i-1];
      if((i-sz) >=0) ans = max(ans, pre[i] - pre[i-sz]);
    }
    ans = max(ans, pre[sz-1]);
    std::cout << "Case #"<<(ix++)<<": ";
    std::cout << ans << '\n';
    // // std::cout << (1UL<<50) << '\n';
  }
  return 0;
}
