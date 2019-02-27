#include <bits/stdc++.h>
using namespace std;

string vectostr(vector<int> &v)
{
  string hash;
  for(int i=0; i<26;i++)
  {
    hash += char('A' + i);
    hash+=to_string(v[i]);
  }
  // std::cout << hash << '\n';
  return hash;
}


int main()
{
  long int t; cin>>t;
  long int ix=1;
  while(t--)
  {
    long int l; cin>>l;
    string a,b; cin>>a>>b;

    // std::unordered_set<std::string> first;
    // unordered_set<vector<int> > s;
    unordered_set< string > s;



    //add all to set
    for(int i =0; i<l; i++)
    {
      vector<int> temp(26, 0);
      for(int j =i; j<l; j++)
      {
        temp[b[j]-'A']++;
        s.insert(vectostr(temp));
      }
    }

    // //calculate substrings
    long int ans = 0;
    for(int i =0; i<l; i++)
    {
      vector<int> temp(26, 0);
      for(int j =i; j<l; j++)
      {
        temp[a[j]-'A']++;
        if(s.find(vectostr(temp))!=s.end()) ans++;
      }
    }

    std::cout << "Case #"<<(ix++)<<": ";
    std::cout << ans << '\n';
  }
  return 0;
}
