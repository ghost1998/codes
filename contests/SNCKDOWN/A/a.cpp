#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n; cin>>n;

    vector<string> v;
    string temp;
    for(int i =0; i<n;i++) cin>>temp,  v.push_back(temp);
    // std::cout << v.size() << '\n';

    map<string, long int> mp;
    long int ans=0;
    for(int i=0; i<v.size(); i++)
    {
      if(mp.find(v[i]) == mp.end())
      {
        long int tempans = 2;
        int flag=0;

        for(int j=1; j<v[i].size(); j++)
        {
          flag =0;
          if(j>0)
          {
            if((v[i][j]=='d' ||v[i][j]=='f') && (v[i][j-1]=='j' ||v[i][j-1]=='k')) flag=1;
            if((v[i][j]=='j' ||v[i][j]=='k') && (v[i][j-1]=='d' ||v[i][j-1]=='f')) flag=1;
          }
          tempans += (flag==0) ? 4: 2;

        }

        // std::cout << tempans << '\n';
        mp[v[i]] = tempans;
        ans+=tempans;
      }
      else
      {
        ans+=mp[v[i]]/(2);
        // std::cout << mp[v[i]]/2<< '\n';
      }
    }

    std::cout << ans << '\n';
  }
  return 0;
}
