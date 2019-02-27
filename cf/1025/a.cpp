#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n; cin>>n;
  string s; cin>>s;
  vector<int> ct(26,0);
  int pos = 0;
  for(int i =0; i<s.size(); i++)
  {
    ct[s[i] - 'a']++;
    if(ct[s[i] - 'a'] >= 2)
    {
      pos = 1;
      break;
    }
  }

  if(pos || n==1) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}
