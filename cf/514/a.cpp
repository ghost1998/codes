#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int n, l, a;
  cin>>n>>l>>a;
  long int start = 0;
  long int ans = 0;
  for(int i =0; i<n; i++)
  {
    int ti, li;
    cin>>ti>>li;
    while(start+ a <= l && start + a <=ti ) ans++ , start +=a;
    start = ti+li;
  }

  while(start+ a <= l  ) ans++ , start +=a;
  std::cout << ans << '\n';
  return 0;
}
