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


void check(long int a[], long int n, long int &ans, long int i, long int sum)
{
  if(i==n)
  {
    if((sum) % 360 ==0)  ans = 1;
    return;
  }
  check(a, n, ans, i+1, sum+a[i]);
  check(a, n, ans, i+1, sum-a[i]);
  return;
}
int main()
{
  long int n; cin>>n;
  long int ans = 0;
  long int a[n+1];
  for(int i=0; i <n ; i++) cin>>a[i];
  check(a, n, ans, 0, 0);
  if(ans) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
  return 0;
}
