#include <bits/stdc++.h>
using namespace std;


int dfs(long int current, vector<long int>  *adj, vector<long int>  &vis, vector<long int>  &fav)
{
  int ans = 1;


  for(int i=0; i< adj[current].size(); i++)
  {
    if(vis[adj[current][i]]==0)
    {
      vis[adj[current][i]]=1;
      if((fav[adj[current][i]] != current) && (fav[adj[current][i]] != fav[current]) ) return 0;
      ans = ans  & dfs(adj[current][i], adj, vis, fav);
    }

  }

  return ans;

}


int main()
{
  int t;cin>>t;
  while(t--)
  {
    long int n; cin>>n;
    // std::cout << n << '\n';
    vector<long int> adj[n+2];
    vector<long int> vis(n+2, 0);
    vector<long int> fav(n+2, 0);
    for(int i=0; i<n-1;i++)
    {
      long int a, b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int i=1; i<=n;i++)
    {
      cin>>fav[i];
    }

    vis[1] = 1;
    int ans = dfs(1, adj, vis, fav);
    std::cout << 2*ans -1 << '\n';
  }
  return 0;
}
