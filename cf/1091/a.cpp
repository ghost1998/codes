#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,c; cin>>a>>b>>c;
  long long ans = 3 + 3*min(c-2, min(a, b-1));
  std::cout << ans << '\n';
  return 0;
}
