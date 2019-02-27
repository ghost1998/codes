#include<bits/stdc++.h>
using namespace std;

void dfs(long int current,vector<long int>  *adj, vector<long int>  &vis, vector<long int>  &par)
{
  par.push_back(current);

  for(int i=0; i< adj[current].size(); i++)
  {

    if(vis[adj[current][i]]==0)
    {
      std::cout << current<<" "<< adj[current][i]<< '\n';
      vis[adj[current][i]] = !(rand() % 2 == 1) ? current: vis[current];
      vis[adj[current][i]] = (rand() % 500 == 1) ? vis[adj[current][i]] : vis[par[ (rand() % par.size())  ]] ;
      dfs(adj[current][i], adj, vis, par);
    }

  }
  par.pop_back();

}


int main()
{
  int t;cin>>t;
  while(t--)
  {
    long int n; cin>>n;
    vector<long int> adj[n+2];
    vector<long int> vis(n+2, 0);
    vector< pair<long int, long int> > edges;
    for(int i=0; i<n-1;i++)
    {
      long int a, b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      edges.push_back( make_pair(a,b) );
    }

    // long int ans = 2* (rand() % 2) -1;
    vis[1] = 1;

    // std::cout << "-----------------" << '\n';
    std::cout << n << '\n';
    vector<long int> par;
    dfs(1, adj, vis, par);
    // for(int i=0; i< n; i++)
    // {
    //   std::cout << vis[i+1] << ' ';
    // }
    // std::cout  << '\n';
    // for(int i=0; i<n-1;i++)
    // {
    //   std::cout << edges[i].first<<" "<<edges[i].second << '\n';
    // }
    // break;
  }
  return 0;
}
