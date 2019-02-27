#include <bits/stdc++.h>
using namespace std;


int dfs(long int current, vector<long int>  *adj, vector<long int>  &vis, int mx = 1)
{
  //Goal is to get the maximum from the tree we are at current.
  int ans = mx ? -1000 : 10000;

  // std::cout << "----------" << '\n';
  // std::cout << current << '\n';
  // std::cout << mx << '\n';

  if(adj[current].size() ==0) return current;

  for(int i=0; i< adj[current].size(); i++)
  {
    if(vis[adj[current][i]]==0)
    {
      vis[adj[current][i]]=1;
      if(mx) ans = max(ans, dfs(adj[current][i], adj, vis, 1-mx));
      else ans = min(ans, dfs(adj[current][i], adj, vis, 1-mx));
    }

  }

  return ans + current;

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

    for(int i=0; i<n-1;i++)
    {
      long int a, b; cin>>a>>b;
      adj[a].push_back(b);
      // adj[b].push_back(a);
    }

    vis[1] = 1;
    int ans = dfs(1, adj, vis, 1);
    std::cout << ans << '\n';
  }
  return 0;
}
