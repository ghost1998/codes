#include <bits/stdc++.h>
using namespace std;

int power(int x,  int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


int main()
{
  long int t; cin>>t;
  while(t--)
  {
    int a, b, c; cin>>a>>b>>c;
    std::cout << power(a,b,c) << '\n';
  }
  return 0;
}
