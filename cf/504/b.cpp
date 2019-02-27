#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int a, b;
  cin>>a>>b;
  // cout<<b-1<<endl;
  if(b-1 <= a && b-1 >=2)
  {

    long long int total = b-1;
    long long int ans = (total)/2;
    cout<<ans<<endl;
  }
  else if(b-a <=a-1 && b-a>=1)
  {
    long long int total = a - (b-a-1);
    long long int ans = (total)/2;
    cout<<ans<<endl;
  }
  else
  {
    cout<<0<<endl;
  }
  return 0;
}
