#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n; cin>>n;
  vector<long long> v;

  for(int i =1; i*i <=n; i++)
  {
    if(n%i==0)
    {
      long long sum = ((2 + n-i)*(n/i))/2;
      // std::cout <<i<<" "<< sum << '\n';
      v.push_back(sum);

      if(i*i == n) continue;

      sum = ((2 + n-(n/i))*(i))/2;
      // std::cout <<n/i<<" "<< sum << '\n';
      v.push_back(sum);

    }
  }
  sort(v.begin(), v.end());

  for(int i=0; i <v.size(); i++) std::cout << v[i]<<" ";
  std::cout  << '\n';
  return 0;
}

//
// 12 2
// 1 3 5 7 9 11
// 0 2 4 6 8 10
//
// 12 3
// 1 4 7 10
// 0 3 6 9
//
//
// first = 1
// last  = 1 + n - i
// num. terms = n/i
// sum =  ((2 + n-i)*(n/i))/2;
//
// 16
// 1 5 9 13
// 0 4 8 12
//
// 14 *2 = 28
