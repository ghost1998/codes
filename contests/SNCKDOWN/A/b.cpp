#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &v, vector<int> ar[], vector<int> &vis, int n, int i )
{

  vis[i]=1;

  for(int j = 0; j < ar[i].size(); j++)
  {
    if(vis[ar[i][j]] ==0 )dfs(v, ar, vis,  n, ar[i][j]);
  }

  return;


}

int check(vector<int> &v)
{
  int n = v.size();

  // int gcd = __gcd(v[0], v[1]);
  // for(int i=1; i<n;i++) gcd = __gcd(v[i-1], v[i]);




  vector<int> ar[n+1];
  for(int i=0; i<n;i++) for(int j=0; j<n;j++) if(__gcd(v[i], v[j]) ==1) ar[i].push_back(j), ar[j].push_back(i);
  vector<int> vis(n,0);

  dfs(v, ar, vis,  n, 0);

  for(int i =0; i <vis.size(); i++) if(vis[i]==0) return 0;
  return 1;
}

int main()
{
  int t; cin>>t;

  while(t--)
  {
    int n; cin>>n;
    vector<int> ar[n+1];
    vector<int> v;
    // vector<int> vis(n,0);
    int temp;

    for(int i=0; i<n;i++) cin>>temp, v.push_back(temp);

    if(check(v) ==1)
    {
      std::cout << 0 << '\n';
      for(int i=0; i<n;i++) std::cout << v[i]<<" ";
      std::cout << '\n';
      continue;
    }

    int flag = 0;
    for(int i=0; i<n;i++) if(v[i]!=47) flag=1;

    v[0] = (flag==0)?43:47;
    std::cout << 1 << '\n';
      for(int i=0; i<n;i++) std::cout << v[i]<<" ";
      std::cout << '\n';

    // if(check(v) ==1)
    // {
    //   std::cout << 1 << '\n';
    //   for(int i=0; i<n;i++) std::cout << v[i]<<" ";
    //   std::cout << '\n';
    //   continue;
    // }
    //
    // v[0] = 43;
    // if(check(v) ==1)
    // {
    //   std::cout << 1 << '\n';
    //   for(int i=0; i<n;i++) std::cout << v[i]<<" ";
    //   std::cout << '\n';
    // }

    // for(int i=0; i<n;i++) for(int j=0; j<n;j++) if(__gcd(v[i], v[j]) ==1) ar[i].push_back(j), ar[j].push_back(i);



  }
  return 0;
}
