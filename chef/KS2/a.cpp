#include <bits/stdc++.h>
using namespace std;

int check(string &a, string &b)
{
  if(a.size() ==0) return 0;
  if(b.size() < a.size()) return 0;
  int i=0;
  while(a[i] == b[i] && i<a.size()) i++;
  if(i==a.size()) return 1;
  return 0;
}
int main()
{
  long int ix=1;
  long int t; cin>>t;
  while(t--)
  {
    // qw++;
    long int n, p; cin>>n>>p;
    std::vector<string> v;
    string temp;
    for(int i=0; i<p;i++) cin>>temp, v.push_back(temp);

    for(int i=0; i<v.size();i++) for(int j=0; j<v.size();j++)
    {
      if(i==j) continue;
      if(check(v[i], v[j])) v[j] = "";
    }

    // std::cout << v.size() << '\n';
    // for(int i=0; i<v.size();i++) std::cout << v[i] << '\n';

    long long int ans = 1UL<<n;
    // std::cout << ans << '\n';
    for(int i=0; i<v.size();i++)
    {
      if(v[i].size() > 0)   ans -= 1UL<<(n-v[i].size());
    }
    std::cout << "Case #"<<(ix++)<<": ";
    std::cout << ans << '\n';
    // std::cout << (1UL<<50) << '\n';
  }
  return 0;
}
