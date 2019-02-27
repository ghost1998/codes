#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, q;
  cin>>n>>q;
  int ar[n];
  int mark[n];
  int hi[q+2];
  int lo[q+2];
  int np =0;
  for(int i =0; i<q+2; i++) hi[i] = -1, lo[i] = n+1;
  for(int i =0; i<n; i++)
  {
    cin>>ar[i];
    mark[i] = -1;
    hi[ar[i]] = max(hi[ar[i]], i);
    lo[ar[i]] = min(lo[ar[i]], i);
  }

  for(int i =q; i>=1; i--)
  {
    if(np==1) break;
    if(hi[i] == -1)
    {
      // do nothing
    }

    else //element exists
    {
      for(int j = lo[i] ; j <= hi[i] ;)
      {
        if(mark[j]!=-1)
        {
          j = mark[j]+1;
        }

        else
        {
          if(ar[j]>0 && ar[j]<i)
          {
            np = 1;
            cout<<"NO"<<endl;
            return 0;
          }

          else
          {
            mark[j] = hi[i];
            ar[j] = i;
          }
          j = j+1;
        }


      }

    }
  }

  

  if(np==1) cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    for(int i =0; i<n; i++)
    {
      if(ar[i] == 0) ar[i] = 1;
      cout<<ar[i]<<' ';
    }
    cout<<endl;
  }
  return 0;
}
