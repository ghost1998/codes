#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n; cin>>n;
  long long x=0, y=0, tx=0, ty=0;
  for(int i = 0; i <2*n; i++) cin>>tx>>ty , x+=tx, y+=ty;
  std::cout << x/n<<" "<<y/n << '\n';
  return 0;
}
