#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s; cin>>s;
  int ans = -1;

  int a=1,b=1,c=1;
  for(int i =1 ; i<s.size(); i++)
  {
    if(s[i] == s[i-1]) break;
    a++;
  }

  for(int i =s.size()-2 ; i>=0; i--)
  {
    if(s[i] == s[i+1]) break;
    b++;
  }

  int temp =1;
  for(int i =1 ; i<s.size(); i++)
  {
    if(s[i] == s[i-1])
    {
      c = max(temp,c);
      temp = 1;
    }
    else
    {
      temp++;
      c = max(temp,c);
    }
  }
  // std::cout << a<< " "<<b<<" "<<c << '\n';

  if(s[0] != s[s.size()-1] && a<s.size() )
  {
    c = max(c, a+b);
  }

  // std::cout << a<< " "<<b<<" "<<c << '\n';
  std::cout << c << '\n';
  return 0;
}
