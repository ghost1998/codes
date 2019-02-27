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
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  ll n; cin>>n;
  char c; ll a,b;
  ll c1=0, c2=0;
  while(n--)
  {
    // scanf("%c", &c);
    // scanf(" %lld",&a );
    // scanf(" %lld", &b );
    cin>> c>>a>>b;
    // std::cout << a+b << '\n';
    if(a<b) swap(a,b);
    if(c=='+')
    {


      if(a> c1) swap(a,c1), swap(b, c2);
      c2 = max(c2, b);
    }
    if(c=='?')
    {
      if(c1<=a && c2<=b) std::cout << "YES" << '\n';
      else std::cout << "NO" << '\n';
    }

  }
  return 0;
}
