#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
// //
vector<long int> helper(long int ar[],  unordered_map <pair<long int, long int> , vector<long int> > &dp,  long int lo, long int hi)
{
  // std::cout << lo<<" "<<hi << '\n';
  if(dp.find(make_pair(lo, hi)) != dp.end()) return dp[make_pair(lo, hi)];

  vector<long int> temp_vec;
  // dp.insert(make_pair(make_pair(lo, hi), temp_vec));


  if(lo==hi)
  {
    temp_vec.push_back(ar[lo]);
    dp.insert(make_pair(make_pair(lo, hi), temp_vec));
    return dp[make_pair(lo, hi)];
  }

  for(int i =lo; i<=hi; i++)
  {
    int leftpos = 1;
    if(i>lo)
    {
      leftpos = 0;
      vector<long int> temp = helper(ar, dp, lo, i-1);

      for(int j =0;j<temp.size();j++)
      {
        if(__gcd(ar[i], temp[j]) !=1) leftpos = 1;
        break;
      }

    }

    if(leftpos==0) break;
    int rightpos = 1;
    if(i<hi)
    {
      rightpos = 0;
      vector<long int> temp = helper(ar,dp, i+1, hi);

      for(int j =0;j<temp.size();j++)
      {
        if(__gcd(ar[i], temp[j]) !=1) rightpos = 1;
        break;
      }
    }


    if(leftpos && rightpos) temp_vec.push_back(ar[i]);
  }


  if(temp_vec.size() ==0) temp_vec.push_back(1);

  dp.insert(make_pair(make_pair(lo, hi), temp_vec));
  return dp[make_pair(lo, hi)];
}

int main()
{
  long int n;
  cin>>n;
  long int ar[n]; for(int i =0;i<n;i++) cin>>ar[i];

  unordered_map <pair<long int, long int> , vector<long int>, pair_hash > dp;

  // vector<long int> ans = helper(ar, dp, 0, n-1);
  // // std::cout << ans.size() << '\n';
  //
  // if(ans.size() == 1 && ans[0]==1) std::cout << "No" << '\n';
  // else std::cout << "Yes" << '\n';
  return 0;
}
