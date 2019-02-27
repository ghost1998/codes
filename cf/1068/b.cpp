#include <bits/stdc++.h>
using namespace std;

long long int helper(long long int n)
{
    long long int count = 0;
    for (long long int i = 1; i <= sqrt(n); i++)
    {
        if (n%i ==0) count = (n / i == i) ? count+1 : count+2;

    }
    return count;
}

int main()
{
  long long int b; cin>>b;
  std::cout << helper(b) << '\n';
  return 0;
}

// lcm(a, b)/a = (b)/  gcd(a, b)
