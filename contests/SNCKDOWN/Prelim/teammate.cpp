#include <bits/stdc++.h>
using namespace std;
long int fac[1000010];
#define m 1000000007

long int power(long int x,long int y)
{
  long int ans=1;
  // cout<<x<<" "<<y<<endl;
  while(y>0)
  {
    if((y&1)==1)
    {
      ans=(ans*x)%m;
    }
    y=(y>>1);
    x=(x*x)%m;
  }
  // cout<<ans<<endl;
  return ans;
}

long int calc(long int n)
{
  long int num = fac[n];
  long int den = (fac[n/2] * power(2,n/2))%m;
  // cout<<num<<" "<<den<<" "<<(num*power(den,m-2))%m<<endl;
  return (num*power(den,m-2))%m;
}

int main()
{
  fac[0] = 1;
  for(long int i=1;i<1000009;i++)
  {
    fac[i] = (fac[i-1] * i) % m;
  }
  int t;cin>>t;
  while(t--)
  {
    long int n; cin>>n;

    map<long int,long int> mp;
    for(long int i=0;i<n;i++)
    {
      long int temp;
      cin>>temp;
      if(mp.find(temp) == mp.end()) mp[temp] = 0;
      mp[temp]++;
    }

    long int ans = 1;
    long int carry = 0;
    long int present = 0;
    map<long int,long int>::reverse_iterator it ;
    for(it= mp.rbegin(); it!=mp.rend(); it++)
    {
      long int total = it->second;
      if(carry==1)
      {
        if(total%2==0)
        {
          ans=(ans*total)%m;
          ans=(ans*(total-1))%m;
          ans=(ans*calc(total-2))%m;
          carry=1;
        }
        else
        {
          ans=(ans*total)%m;
          ans=(ans*calc(total-1))%m;
          carry=0;
        }
      }
      else
      {
          if(total%2==0)
          {
            ans=(ans*calc(total))%m;
            carry=0;
          }
          else
          {
            ans=(ans*total)%m;
            ans=(ans*calc(total-1))%m;
            carry=1;
          }
      }
      // if(carry == 1)
      // {
      //   ans = (ans+total)%mod;
      //   total--;
      // }
      //
      // if(total%2==1) carry = 1, total--;
      // else carry = 0;
      //
      // ans = (ans + calc(total/2))%mod;
    }

    std::cout << ans << '\n';
  }
  return 0;
}
