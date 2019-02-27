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
  string a[5];
  for(int i=0; i <5; i++) cin>>a[i];
  int ans =0;

  for(int i=0; i <5; i++)
  {
    if(s[0] == a[i][0] || s[1]==a[i][1]) ans = 1;
    if(ans) break;

  }
  if(ans) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
  return 0;
}
