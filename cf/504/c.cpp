#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  stack<int> st;
  int l=0;
  for(int i=0;i<s.size();i++)
  {
    if(l==k) break;
    if(s[i] == '(') st.push(i);
    if(s[i] == ')')
    {
      if(!st.empty())
      {
        int temp = st.top();
        st.pop();
        s[temp] = '-';
        s[i] = '+';
        l+=2;

      }
    }
  }

  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='-') cout<<"(";
    if(s[i]=='+') cout<<")";
  }
  cout<<"\n";
  return 0;
}
