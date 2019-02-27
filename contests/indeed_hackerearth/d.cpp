#include <bits/stdc++.h>
using namespace std;

long int helper(long long int n)
{
    long int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int main()
{
  long int n, m , q; cin>>n>>m;

  std::vector<long int> adj[n+2];

  long int ar[n+1][n+1];
  long int ans[n+1][n+1];
  for(int i=0; i<n+1; i++) for(int j=0; j<n+1; j++) ar[i][j] = 0, ans[i][j] = 0;

  for(int i=0; i<m; i++)
  {
    long int a, b;
    cin>>a >>b;

    ar[a][b] = 1;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  map<long int, long long int> mp;

  for(int i=1; i<=n; i++)
  {
    long long int temp = 0;
    for(int j = 0; j< adj[i].size() ; j++)
    {
      if((temp & 1<<(adj[i][j])) ==0 ) temp+=1<<(adj[i][j]);
    }
    mp.insert(make_pair(i, temp));
  }

  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      long long int inter = mp[i] & mp[j];
      long int card = helper(inter);
      ans[i][j] = card;
      ans[j][i] = card;
    }
  }



  cin>>q;
  for(int i=0; i<q; i++)
  {
    long int a,b; cin>>a>>b;

    std::cout << ans[a][b] << '\n';
  }
  return 0;
}


// 5 6
// 1 2
// 2 3
// 3 4
// 4 1
// 5 1
// 3 5
// 4
// 1 2
// 2 3
// 3 4
// 4 5
// ------------------
// 1 : 2 4 5
// 2 : 1 3

// 1 0 1 1
