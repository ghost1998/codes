#include <bits/stdc++.h>
using namespace std;

// // 10101 10
// // 01101 10
// //
// a  = x +  (a^x)
// ith = a[i] ^ (x[i] ^ x[i]) ^ carry = a[i]
// ith = a[i]  ^ carry = a[i]
// // long int helper(long long int a, long long int x, int idx, int carry)
// // {
// //   //check if 1 is possible
// //   ( (a&(1<<idx)!=0)  ^ carry) == (a&(1<<idx)!=0)
// //
// //
// //   //check if 0 is possible
// //
// // }
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    long long int a;
    cin>>a;
    long long int set = 0;
    // long long int x = 0;
    // int ans = helper(a, x, 0, 0);
    for(int i = 0; i<31;i++)
    {
      if(a&(1<<i)) set++;
    }
    // std::cout << set<< " "<<(1<<set) << '\n';
    std::cout <<(1<<set) << '\n';
  }
  return 0;
}
