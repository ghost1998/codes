#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<long int> a;
  long int temp;
  cin>>temp;
  a.push_back(temp);
  cin>>temp;
  a.push_back(temp);
  cin>>temp;
  a.push_back(temp);

  sort(a.begin(), a.end());
  if(a[2] < a[1] + a[0]) std::cout << 0 << '\n';
  else std::cout << 1 + a[2]-a[1]-a[0] << '\n';
  return 0;
}
