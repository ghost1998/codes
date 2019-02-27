#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long t; cin>>t;
  while(t--)
  {
    long long angle; cin>>angle;
    if(angle>=180)
    {
      std::cout << "-1" << '\n';
      break;
    }
    long long alpha = 2* angle;
    long long total = 360/ __gcd((long long)360, alpha);
    if( 180/(total) + angle == 180) total = 2 * total;
    std::cout << total << '\n';
  }
  return 0;
}
