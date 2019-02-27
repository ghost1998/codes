#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    long long sum, exor, nd; sum = x; exor=y;; nd = (sum-exor)>>1;
    long long a,b; a=0;b=0;

    if(nd<0)
    {
      ans.push_back(-1);
    }

    else
    {
      for(int i=0;i<66;i++)
      {
        if(exor&1)
        {
          a += 0;
          b+= 1<<i;
        }

        else
        {
          if(nd&1)
          {
            a+= 1<<i;
            b+= 1<<i;
          }
        }

        exor = exor>>1;
        nd = nd>>1;

      }

      ans.push_back(a);
      ans.push_back(b);
    }

  }
  return 0;
}

//       and    xor
// 0 0   0       0
// 0 1   0       1
// 1 0   0       1
// 1 1   1       0
