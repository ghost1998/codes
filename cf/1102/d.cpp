#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long int li;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double ld;

#define mp make_pair
#define f first
#define s second

#define pu push
#define pb push_back

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())


int main()
{
  ll n; cin>>n;
  string s; cin>>s;
  ll a=0, b=0, c=0;
  rep(i, n)
  {
    if(s[i] == '0') a++;
    if(s[i] == '1') b++;
    if(s[i] == '2') c++;
  }

  // std::cout << a<<b<<c << '\n';

  if(a> n/3) //remove zeroes from the end
  {
    for(int i = n-1; i>=0; i--)
    {
      if(a== n/3) break;
      if(s[i] == '0')
      {
        if(c<n/3) s[i] = '2' , c++, a--;
        else s[i] = '1', b++, a--;
      }
    }
  }

  if(a< n/3)
  {
    rep(i, n)
    {
      if(a== n/3) break;
      if(s[i] == '1' && b>n/3) s[i] = '0', b--, a++;
      if(s[i] == '2' && c>n/3) s[i] = '0', c--, a++;
    }
  }


  if(b> n/3)
  {
    for(int i = n-1; i>=0; i--)
    {
      if(b==n/3) break;
      if(s[i] == '1')
      {
        if(c<n/3) s[i] = '2', c++, b--;
      }
    }
  }

  if(b<n/3)
  {
    rep(i, n)
    {
      if(b==n/3) break;
      if(s[i]== '2' && c>n/3) s[i] = '1', b++, c--;
    }
  }
  // std::cout << a<<b<<c << '\n';

  std::cout << s << '\n';
  return 0;
}
