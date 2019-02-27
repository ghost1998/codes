#include <bits/stdc++.h>
using namespace std;


helper(xoff, yoff, idx, ans)
{
  long int x = xoff[idx]+1;
  long int y=yoff[idx];


  for(long int i=0; i<v[idx].size(); i++)
  {
    if(v[idx][i] > idx)
    {
      ans[v[idx][i]].push_back(make_pair(x, y));
      ans[v[idx][i]].push_back(make_pair(xoff[v[idx][i]], y);
      x++;y++;

    }
  }
}


int main()
{
  long int n, m; cin>>n>>m;
  long int a,b;
  long int temp;

  vector<long int> v[n+2];
  vector<long int> smaller_than(n+2, 0);
  vector<long int> xoff(n+2, 0);
  vector<long int> yoff(n+2, 0);

  for(long int i=0; i<m;i++)
  {
    cin>>a>>b;
    temp = a;
    a = min(a, b);
    b = max(temp, b);

    v[a].push_back(b);
    v[b].push_back(a);

    smaller_than[b]++;


  }



  xoff[1] = 1;
  yoff[1] = 1;

  for(int i=2; i<=n;i++)
  {
    xoff[i] = xoff[i-1] + (v[i-1] - smaller_than[i-1] +1);
    yoff[i] = yoff[i-1] + (v[i-1] - smaller_than[i-1] );
  }

  for(int i=1; i<=n;i++)
  {
    long int x = xoff[idx];
    long int y=yoff[idx];
    ans[i].push_back(make_pair(x, y));
    x++;

    for(int j = 0 ; j< (v[i] - smaller_than[i] +1))     ans[i].push_back(make_pair(x, y+j));


  }



  return 0;
}
