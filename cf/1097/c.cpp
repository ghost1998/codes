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
  string a[n+1];
  rep(i, n) cin>>a[i];
  long int ans = 0;
  map<ll, long int> mp;
  rep(i,n)
  {
    vector<char> s;
    rep(j,a[i].size())
    {
      if(s.size() >0 && s[s.size()-1] == '(' && a[i][j]==')') s.pop_back();
      else s.push_back(a[i][j]);
    }
    // rep(i, s.size()) std::cout << s[i] << ' ';
    // std::cout << -1*((ll )s.size()) << '\n';
    if(s.size() ==0 ) mp[0]++;
    else if(s[0] == '(' && s[s.size()-1] == '(')
    {
      //opening
      mp[((ll )s.size())]++;
      // std::cout << ( s.size()) <<" "<< mp[ s.size()]<< '\n';

    }

    else if(s[0] == ')' && s[s.size()-1] == ')')
    {
      //opening
      mp[-1 * ((ll )s.size())]++;
      // std::cout << (-1 * s.size()) <<" "<< mp[-1 * s.size()]<< '\n';
    }
  }
  // std::cout << "----" << '\n';
  // std::cout << mp[0] << '\n';
  for(map<ll, long int>:: iterator it = mp.begin(); it!=mp.end(); it++)
  {
    // std::cout << it->first<<" " <<it->second << '\n';
    if((it->first) ==0) ans+=(it->second/2);
    else if((it->first)  > 0) ans+= (min(mp[it->first], mp[(-1 * (it->first))]));

  }
  std::cout << ans << '\n';
  return 0;
}
