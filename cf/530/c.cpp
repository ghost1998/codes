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
  string s; cin>>s;
  ll k; cin>>k;
  ll qm=0, ast= 0, let = 0;
  rep(i, s.size())
  {
    if(s[i] =='?') qm++;
    else if(s[i] =='*') ast++ ;
    else let++;
  }
  if(let==0)
  {
    if(k==0)
    {
      std::cout << "" << '\n';
    }

    else
    {
      std::cout << "Impossible" << '\n';
    }

    return 0;
  }

  ll mn=let, mx=let;
  mn = let - qm - ast;
  if(ast>0) mx += 500;
  // std::cout << mn<<" "<<mx << '\n';

  if(k<mn || k>mx)
  {
    std::cout << "Impossible" << '\n';
    return 0;
  }

  string ans;

  if(ast>0)
  {
    int flag = 1;
    rep(i, s.size())
    {
      if(s[i] != '*' && s[i] != '?')
      {
        if(i+1<= s.size()-1 && s[i+1] == '*')
        {
          if(flag)
          {
            int temp = k - mn;
            while(temp--) ans+= s[i];
            flag = 0;
          }

          // ans+= s[i];

        }

        else if(i+1<= s.size()-1 && s[i+1] == '?')
        {

        }
        else ans+= s[i];


      }
    }
  }

  else
  {
    int tmp = mx - k;
    rep(i, s.size())
    {
      if(s[i] != '*' && s[i] != '?')
      {
        if(i+1<= s.size()-1 && s[i+1] == '?' && tmp > 0)
        {
          tmp--;
        }
        else ans+= s[i];
      }
    }

  }
  // std::cout << ans.size() << '\n';
  std::cout << ans << '\n';
  return 0;
}
