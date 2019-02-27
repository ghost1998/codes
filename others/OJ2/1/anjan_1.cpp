#include<bits/stdc++.h>
using namespace std;

void dfs(long int current,long int depth, long int &farthest, long int &distance_max, vector<long int>  *adj, vector<long int>  &vis)
{
  if(vis[current]==1) return;
  vis[current]=1;

  if(depth > distance_max)
  {
    distance_max = depth;
    farthest = current;
  }
  for(int i=0; i< adj[current].size(); i++)
  {
    dfs(adj[current][i],depth+1, farthest, distance_max, adj, vis);
  }

}


int main()
{
  int t;cin>>t;
  int qw=0;
  while(t--)
  {
    qw++;
    long int n; cin>>n;
    vector<long int> adj[n+2];
    vector<long int> vis(n+2, 0);
    for(int i=0; i<n-1;i++)
    {
      long int a, b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    long int distance_max=1;
    long int depth = 1;
    long int farthest =1;
    dfs(1,depth, farthest, distance_max, adj, vis);

    for(int i=0; i<vis.size(); i++) vis[i] =0;

    depth = 1;
    long int start = farthest;
    distance_max = 1;

    dfs(start,depth, farthest, distance_max, adj, vis);

    std::cout << distance_max << '\n';
    // std::cout << adj[1].size() << '\n';
  }
}
