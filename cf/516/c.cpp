#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int l;
  cin>>l;
  string s; cin>>s;

  long int a[27];
  for(int i=0;i<27;i++) a[i]=0;

  for(int i=0; i<s.size() ; i++) a[s[i] - 'a']++;
  for(int i=0;i<26;i++)
  {

    for(int j =0; j<a[i]; j++) std::cout << char('a' + i);
  }

  std::cout  << '\n';
  return 0;
}
