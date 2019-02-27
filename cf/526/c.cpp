#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s; cin>>s;
  char st[s.size()+2];
  int it = 0;
  for(int i =  0; i <s.size(); i++)
  {
    if(s[i]=='a' || s[i]=='b') st[it] = s[i], it++;
  }

  if(it == 0)
  {
    std::cout << 0 << '\n';
    return 0;
  }
  vector<long int> v(it , 0);
  v[0] = (st[0]=='a') ? 1: 0;
  for(int i =  1; i <it; i++)
  {
    if(st[i] == 'a' && st[i-1] == 'a') v[i] = v[i-1];
    if(st[i] == 'a' && st[i-1] == 'b') v[i] = 1+v[i-1];
    if(st[i] == 'b' && st[i-1] == 'a') v[i] = v[i-1];
    if(st[i] == 'b' && st[i-1] == 'b') v[i] = v[i-1];
  }
  long long int ans = 0;
  for(int i =  0; i <it; i++)
  {
    std::cout << i<<" "<<s[i]<<" "<<v[i] << '\n';
    if(st[i] =='a') ans= (ans+v[i])%(1000000007);
  }

  cout<<ans<<endl;

  return 0;
}
