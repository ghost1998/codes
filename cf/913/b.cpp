#include <bits/stdc++.h>
using namespace std;
void dfs(int start, vector<int> &leaf, int &ans, vector<int> adj[])
{
  for(int i=0; i < )
}
int main()
{
  long int n, temp; cin>>n;
  vector<int> adj[n+2];
  for(int i = 1; i <n; i++)
  {
    cin>>temp;
    adj[temp].push_back(i+1);
  }

  int ans=1;
  vector<int> leaf(n+2, -1);
  dfs(1, leaf, ans, adj);
  if(ans==1) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}
