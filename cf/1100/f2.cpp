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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

#define PI 3.14159265


ll getMid(ll s, ll e)
{
	return s + (e - s) / 2;
}


ll constructSTUtil(ll arr[], ll ss, ll se,
					ll* st, ll si)
{
  // return 1;
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	ll mid = getMid(ss, se);

	st[si] = max(constructSTUtil(arr, ss, mid, st,
								si * 2 + 1),
				constructSTUtil(arr, mid + 1, se,
								st, si * 2 + 2));

	return st[si];
}

ll* constructST(ll arr[], ll n)
{
	// Height of segment tree
	ll x = (ll)(ceil(log2(n)));

	// Maximum size of segment tree
	ll max_size = 2 * (ll)pow(2, x) - 1;

	// Allocate memory
	ll* st = new ll[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}

ll MaxUtil(ll* st, ll ss, ll se, ll l,
			ll r, ll node)
{
	// If segment of this node is completely
	// part of given range, then return
	// the max of segment
	if (l <= ss && r >= se)
		return st[node];

	// If segment of this node does not
	// belong to given range
	if (se < l || ss > r)
		return -1;

	// If segment of this node is partially
	// the part of given range
	ll mid = getMid(ss, se);

	return max(MaxUtil(st, ss, mid, l, r,
					2 * node + 1),
			MaxUtil(st, mid + 1, se, l,
					r, 2 * node + 2));
}



int main()
{

  ll n; cin>>n;
  ll arr[n];
  rep(i, n) cin>>arr[i];

  ll* st = constructST(arr, n);

  ll q; cin>>q;
  rep(i, q)
  {
    // std::cout << "here" << '\n';
    ll left, right;
    cin>> left>> right;


    std::cout << MaxUtil(st, 0, n - 1, left-1, right-1, 0) << '\n';
  }
  // std::cout << result << '\n';
  return 0;
}
