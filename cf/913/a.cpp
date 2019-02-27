#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b, ans; cin>>a>>b;
  if(a>= 27) ans = b;
  else ans = (b & ((1<<(a)) -1));
  // std::cout << ((1<<(a)) -1) << '\n';
  std::cout << ans << '\n';
  // std::cout << (1<<(a+1))  << '\n';
  return 0;
}
