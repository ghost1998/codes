#include <bits/stdc++.h>
using namespace std;

void primeFactors(long long int n, set<long long int> &mp)
{
    while (n%2 == 0)
    {
        mp.insert(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            mp.insert(i);
            n = n/i;
        }
    }

    if (n > 2)
        mp.insert(n);
}

int main()
{
  int n;
  cin>>n;
  long long int a, b;
  cin>>a>>b;

  set<long long int> mp;
  primeFactors(a, mp);
  primeFactors(b, mp);
  // for(set<long long int>:: iterator i = mp.begin(); i!=mp.end();i++) std::cout << *i << '\n';
  // std::cout << "-----" << '\n';

  int exists = 1;
  for(int i =0; i<n-1;i++)
  {
    if(mp.empty()) exists = 0;
    if(exists == 0) break;
    cin>>a>>b;

    for(set<long long int>:: iterator i = mp.begin(); i!=mp.end();)
    {
      int temp = *i;
      if(a%temp!=0 && b%temp!=0) mp.erase(i++);
      else i++;
    }

    if(mp.empty()) exists = 0;

  }

  if(exists == 0) std::cout << -1 << '\n';
  else std::cout << *(mp.begin()) << '\n';

  return 0;
}
