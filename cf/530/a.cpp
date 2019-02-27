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
  ll w0,h0, w, h; cin>>w0>>h0;
  ll u1,d1; cin>>u1>>d1;
  ll u2,d2; cin>>u2>>d2;
  if(d1<d2) swap(d1, d2) , swap(u1, u2);

  w = w0;
  // std::cout << "----" << '\n';
  //just after first
  h = d1;
  w = max((ll)0, w -u1 + ((h0*(h0+1))/2 - (d1*(d1-1))/2) );
  // std::cout << h<<" "<<w <<" "<< ((h0*(h0+1))/2 - (d1*(d1+1))/2) <<" "<<u1 << '\n';

  h = d2;
  w = max((ll)0, w -u2 + ((d1*(d1-1))/2 - (d2*(d2-1))/2) );
  // std::cout << h<<" "<<w << '\n';


  w += (d2*(d2-1))/2;
  std::cout << w << '\n';

  return 0;
}
