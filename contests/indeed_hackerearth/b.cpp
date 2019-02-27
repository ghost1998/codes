#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    long int n, m; cin>>n>>m;
    long int arr[n+1][m+1];

    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    {
      scanf("%ld", &arr[i][j]);
    }

    long long int curmin1, curmin2, curminel1, curminel2;
    long long int prevmin1=0, prevmin2=0, prevminel=-2;
    long long min1, min2, minel;
    for(int i=0; i<n; i++)
    {
      std::vector<long int> v;
      for(int j=0; j<m; j++) v.push_back(arr[i][j]);
      sort(v.begin(), v.end());

      curmin1 = v[0];
      curmin2 = v[1];
      curmin1 = -1;
      curmin2 = -1;


      for(int j=0; j<m; j++)
      {
        if((arr[i][j] == curmin1) && curminel1==-1) curminel1 = j;
        else if(arr[i][j] == curmin2) curminel2 = j;
      }

      if(curminel1 == prevminel)
      {
          if( (curmin1 + prevmin2) <= (curmin2 + prevmin1))
          {
            min1 = (curmin1 + prevmin2);
            min2 = (curmin2 + prevmin1);
            minel = curminel1;
          }
          else
          {
            min2 = (curmin1 + prevmin2);
            min1 = (curmin2 + prevmin1);
            minel = curminel2;
          }
      }
      else
      {
        min1 = curmin1 + prevmin1;
        min2 = (curmin2 + prevmin1);
        minel = curminel1;
      }

      prevmin1 = min1;
      prevmin2 = min2;
      prevminel = minel;

    }

    std::cout << min1 << '\n';

  }
  return 0;
}
