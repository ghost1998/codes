#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int n, m , k, l ; cin>>n>>m>>k>>l;

  if(n<m) std::cout << "-1" << '\n';

  else
  {
    // std::cout << ((l+k) %m) << '\n';
    long long int temp = (((l+k)%m) ==0) ? (l+k) /m : (((l+k) /m)+1);
    temp = max((long long int)1, temp);

    if(temp * m <= n) std::cout << temp << '\n';
    else std::cout << "-1" << '\n';
  }

  return 0;
}


// (i * m) - k >=l
// (i * m)  >= l + k
// (i * m)  >= l + k
