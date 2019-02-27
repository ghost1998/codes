#include <bits/stdc++.h>
using namespace std;

void dfs(int idx,vector<long int> adj[], vector<long int> &vis, map<long int, vector<long int> >  &mp, int st)
{
  if(vis[idx]==1) return;
  vis[idx] = 1;
  mp[st].push_back(idx);
  for(int i=0; i<adj[idx].size(); i++)
  {
    if(vis[adj[idx][i]] ==0)
    {
      dfs(adj[idx][i], adj, vis, mp, 3-st);
    }
  }
  return;
}

int main()
{
  long int n, m; cin>>n>>m;
  vector<long int> adj[n+2];
  vector<long int> vis(n+2, 0);
  map<long int, vector<long int> > mp;
  std::vector<long int> v1;
  std::vector<long int> v2;
  mp[1] = v1;
  mp[2] = v2;

  for(int i =0; i<m; i++)
  {
    long int a, b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i =1; i<=n; i++)
  {
    if(vis[i]==0)
    {
      dfs(i, adj, vis, mp, 1);
    }
  }

  std::cout << mp[1].size() << '\n';
  for(int i=0; i<mp[1].size(); i++)
  {
    std::cout << mp[1][i] << ' ';
  }
  std::cout  << '\n';

  std::cout << mp[2].size() << '\n';
  for(int i=0; i<mp[2].size(); i++)
  {
    std::cout << mp[2][i] << ' ';
  }
  std::cout  << '\n';
  return 0;
}
