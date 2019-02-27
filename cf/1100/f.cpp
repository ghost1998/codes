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


// CPP code for range maximum query and updates


// A utility function to get the
// middle index of given range.
ll getMid(ll s, ll e)
{
	return s + (e - s) / 2;
}

/* A recursive function to get the sum of
	values in given range of the array.
	The following are parameters for this
	function.

	st	 -> Poller to segment tree
	node	 -> Index of current node in
				the segment tree .
	ss & se -> Starting and ending indexes
				of the segment represented
				by current node, i.e., st[node]
	l & r -> Starting and ending indexes
				of range query */
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

/* A recursive function to update the nodes which
have the given index in their range. The following
are parameters st, ss and se are same as defined
above index -> index of the element to be updated.*/
void updateValue(ll arr[], ll* st, ll ss, ll se,
				ll index, ll value, ll node)
{
	if (index < ss || index > se)
	{
		cout << "Invalid Input" << endl;
		return;
	}

	if (ss == se)
	{
		// update value in array and in segment tree
		arr[index] = value;
		st[node] = value;
	}
	else {
			ll mid = getMid(ss, se);

			if (index >= ss && index <= mid)
				updateValue(arr, st, ss, mid, index,
							value, 2 * node + 1);
			else
				updateValue(arr, st, mid + 1, se,
							index, value, 2 * node + 2);

			st[node] = max(st[2 * node + 1],
					st[2 * node + 2]);
	}
	return;
}

// Return max of elements in range from
// index l (query start) to r (query end).
ll getMax(ll* st, ll n, ll l, ll r)
{
	// Check for erroneous input values
	if (l < 0 || r > n - 1 || l > r)
	{
		return -1;
	}

	return MaxUtil(st, 0, n - 1, l, r, 0);
}

// A recursive function that constructs Segment
// Tree for array[ss..se]. si is index of
// current node in segment tree st
ll constructSTUtil(ll arr[], ll ss, ll se,
					ll* st, ll si)
{
	// If there is one element in array, store
	// it in current node of segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements, then
	// recur for left and right subtrees and
	// store the max of values in this node
	ll mid = getMid(ss, se);

	st[si] = max(constructSTUtil(arr, ss, mid, st,
								si * 2 + 1),
				constructSTUtil(arr, mid + 1, se,
								st, si * 2 + 2));

	return st[si];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree.*/
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

// Driver code
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  std::cout << "start" << '\n';

  ll n; cin>>n;
  std::cout << "qw" << '\n';
  ll arr[n];
  rep(i, n) cin>>arr[i];

  std::cout << "con s" << '\n';
	ll* st = constructST(arr, n);
  std::cout << "con f" << '\n';
  ll q; cin>>q;
  rep(i, q)
  {
    std::cout << "here" << '\n';
    ll left, right;
    cin>> left>>right;

    std::cout << getMax(st, n, left-1, right-1) << '\n';
  }

	// cout << "Max of values in given range = " << getMax(st, n, 1, 3) << endl;


	// Find max after the value is updated
	// cout << "Updated max of values in given range = " << getMax(st, n, 1, 3) << endl;

	return 0;
}
