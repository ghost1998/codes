#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    string s; cin>>s;

    // int ar[s.size()+2]; for(int i=0; i<s.size(); i++) ar[i] = s[i]=='.' ? 0 :;

    map<int, pair<int, int> > mp;


    for(int i=0; i<s.size(); i++)
    {
      if(s[i] != '.')
      {
        int temp = s[i] -'0' ;
        mp.insert((i, make_pair(min(temp, i), min(temp, s.size()-1 -i) )));

        // mp[i] = make_pair(min(temp, i), min(temp, s.size()-1 -i) );
      }
    }

    // int ar[s.size()+2];
    //
    // for(int i=0; i<s.size()+2; i++) ar[i] =-1;
    //
    // int flag = 1;
    // for(int i=0; i<s.size(); i++)
    // {
    //   if(s[i] != '.' && ar[i] !=-1)
    //   {
    //     flag=0; break;
    //   }
    //
    //   else if(s[i] != '.')
    //   {
    //     ar[i] = i;
    //     for(int j = mp[i].first ; j<= mp[i].second ; j++)
    //     {
    //       if(ar[j] != -1) flag=0; break;
    //       else ar[j] = i;
    //     }
    //   }
    // }
    //
    // if(flag==1) std::cout << "safe" << '\n';
    // else std::cout << "unsafe" << '\n';
  }
  return 0;
}
