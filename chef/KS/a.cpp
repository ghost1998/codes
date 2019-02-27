#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t; cin>>t;
  int ix=1;
  while(t--)
  {
    int n; cin>>n;
    std::vector< long long int> v;
    long int idx=0;
    map<long long int, long long  int> mp;

    long long int ones=0, zeros=0;
    for(int i=0; i<n;i++)
    {
      long long int temp;
      cin>>temp;
      if(temp==1) ones++;
      else if(temp==0) zeros++;
      else if(mp.find(temp)==mp.end()) v.push_back(temp),idx++,  mp.insert(make_pair(temp, 1));
      else v.push_back(temp),idx++, mp[temp]++;
    }

    // std::cout << v.size() << '\n';
    sort(v.begin(), v.end());
    long long int ans=0;


    for(int i=0; i<v.size();i++)
    {
      if(mp[v[i]] >1) ans+= ones*(mp[v[i]]*(mp[v[i]]-1))/2;
      for(int j=i+1; j<v.size();j++)
      {

        long long int prod = v[i] * v[j];
        if(mp.find(prod)!= mp.end())
        {
          // std::cout << v[i]<<" "<<v[j]<<" "<<prod << '\n';
          // ans+=mp[prod];

            ans+= mp[prod];

        }
      }
    }

    ans+= ones>=3 ? (ones*(ones-1)*(ones-2))/6 :0;
    ans+= zeros>=3 ? (zeros*(zeros-1)*(zeros-2))/6 :0;

    ans+= zeros>=2? ((zeros*(zeros-1))/2)* (n-zeros) :0;



    std::cout << "Case #"<<(ix++)<<": ";
    std::cout << ans << '\n';
  }
  return 0;
}
