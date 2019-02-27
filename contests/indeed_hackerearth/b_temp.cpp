#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    long int n, m; cin>>n>>m;
    long int arr[n+1][m+1];
    long int b[n+1][m+1];

    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      scanf("%ld", &arr[i][j]);
    }



    long int prevmin1=0, prevmin2=0, prevminel = -2;




    long int min1, min2, minel1, minel2, nwmin1, nwmin2, nwminel;

    for(int i=0; i<n; i++)
    {
      // std::cout << "----" << '\n';
      // std::cout << prevmin1<<" "<<prevmin2 << '\n';

      std::vector<long int> v;

      for(int j=0; j<m; j++) v.push_back(arr[i][j]);
      sort(v.begin(), v.end());

      min1 = v[0]; min2 = v[1];

      for(int j=0; j<m; j++)
      {
        if(arr[i][j] == min1) minel1 = j;
        else if(arr[i][j] == min2) minel2 = j;
      }
      // std::cout << minel1<<" "<<minel2 << '\n';
      // std::cout << min1<<" "<<min2 << '\n';
      // std::cout << prevmin1<<" "<< prevmin2 << '\n';
      // std::cout << prevminel << '\n';

      if(i==0)
      {
        prevmin1 = min1;
        prevmin2 = min2;
        prevminel = minel1;
        continue;
      }
      if(minel1 == prevminel)
      {

        if( (min1+prevmin2) < (min2+ prevmin1) )
        {
          std::cout << "here" << '\n';

          nwmin1 = (min1+prevmin2);
          nwmin2 = (min2+ prevmin1);
          nwminel = minel1;
        }

        else
        {
          nwmin2 = (min1+prevmin2);
          nwmin1 = (min2+ prevmin1);
          nwminel = minel2;
        }

        prevmin1 = nwmin1;
        prevmin2 = nwmin2;
        prevminel = nwminel;
      }

      else
      {
        if( (min1+prevmin2) < (min2+ prevmin1) )
        {
          nwmin1 = (min1+prevmin1);
          nwmin2 = (min1+prevmin2);
          nwminel = minel1;
        }
        else
        {
          nwmin1 = (min1+prevmin1);
          nwmin2 = (min2+ prevmin1);
          nwminel = minel1;
        }
        prevmin1 = nwmin1;
        prevmin2 = nwmin2;
        prevminel = nwminel;
      }


    }
    std::cout << prevmin1 << '\n';

  }
  return 0;
}
