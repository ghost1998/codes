#include <bits/stdc++.h>
using namespace std;


fromtop
tobot
max1
max2
dfs(int start, int fromtop, int tobot, vector< pair<long long, long long> > adj[],vector<int> &vis,  int n )
{
  long long max1=0, max2=0;
  if(vis[start] == 1) return;
  vis[start] = 1;
  for(int i = 0; i < adj[start].size(); i++ )
  {
    long long fromtoptemp = max(gas[adj[start][i].first] , gas[adj[start][i]] + (fromtop - adj[start][i].second ));
    long long tobottemp = 0;
    // call dfs
  }

  // tobot = gas[start]  + max1;
  ans = max(ans, max1+max2-);
}
int main()
{
  long long n ; cin>>n;
  long long gas(n, 0);
  for(int i=0; i < n ; i++) cin>>gas[i];
  vector< pair<long long, long long> > adj[n+2];
  for(int i=0; i < n-1 ; i++)
  {
    long long a,b,c; cin>>a>>b>>c;
    adj[a].push_back({b , c});
    adj[b].push_back({a , c});
  }
  vector<int> vis(n+2, 0);

  return 0;
}
