#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b)
    {
      // return 1;
        // return cntBits(a) < cntBits(b)
        if(a.second.first != b.second.first) return (a.second.first < b.second.first);
        return (a.second.second < b.second.second);
    }
};

int main()
{
  int n, m;
  cin>>n>>m;

  int ix, iy; cin>>ix>>iy;

  int ll, lr; cin>>ll>>lr;
  int ar[n+2][m+2];
  char temp;
  for(int i =0; i<n;i++) for(int j =0; j<m;j++) cin>>temp, ar[i][j] = temp = '*' ? 1  : 0;

  map< pair<int, int>, pair<int, int> > mp;
  priority_queue <  pair<pair <int, int>, pair<int, int> >  > q(cmp);
  q.push(make_pair( make_pair(ix, iy), make_pair(0, 0) ));
  mp[make_pair(ix, iy)] = make_pair(0, 0);

  // int ans = 0;
  // while(!q.empty())
  // {
  //   // pair<pair<int, int>, pair<int, int> curr = q.top();
  //   // q.pop();
  //
  //   int x_new; int y_new;
  //
  //   // x_new = (curr.first).first;
  //   // y_new = (curr.first).second;
  //
  //   // pair<int, int > p_new = make_pair(x_new, y_new)
  //   // if(x_new >=0 && x_new<=n && y_new >=0 && x_new<=m)
  //   // {
  //   //   if(mp.find(p_new) == mp.end())
  //   //   {
  //   //     q.push(p_new);
  //   //   }
  //   // }
  // }
  return 0;
}
