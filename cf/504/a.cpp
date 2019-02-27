#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin>>n;
  cin>>m;
  string s, t;
  cin>>s;
  cin>>t;
  int idx  = -1;
  for(int i=0;i<n;i++)
  {
    if(s[i] == '*') idx = i;
  }

  if(idx==-1)
  {
    if(s.compare(t) == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  else if(m<n-1)
  {
    cout<<"NO"<<endl;
  }
  else
  {
    // cout<<idx<<endl;
    string s1 = s.substr(0,idx);
    // cout<<ft<<endl;
    string s2 = s.substr(idx+1, n-idx-1);

    string t1 = t.substr(0,idx);
    string t2 = t.substr(m-n+1+idx, n-idx-1);

   if(s1.compare(t1) == 0 && s2.compare(t2) == 0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    // if()
  }
  return 0;
}
