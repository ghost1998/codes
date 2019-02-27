#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


typedef long long ll;
typedef long int li;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pli;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double ld;

#define mp make_pair
#define f first
#define s second

#define pu push
#define pb push_back

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define print(x) cout<<x<<endl;
#define printarray(a, start, end) for(ll i=start; i<=end; i++) cout<<a[i]<<" "; cout<<endl;


ll n, m;
// ll A[101][101];
// ll B[101];
ll N=105;

const int SZ = 105;
const ll MOD = 1e9+7;
ll add(ll a, ll b)
{
	ll res = a + b; res%=MOD;
	return res;
}

ll mult(ll a, ll b)
{
	long long res = a;
	res *= b;res%=MOD;
	return res;
}

struct matrix
{
	ll arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(ll i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(ll i=0;i<SZ;i++)
		{
			for(ll j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		res.reset();
		for(ll i=0;i<SZ;i++)
		{
			for(ll k=0;k<SZ;k++)
			{
				// res.arr[i][j] = 0;
				for(ll j=0;j<SZ;j++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};


void qwe (matrix &q , matrix &w)
	{
		matrix res;

		for(ll i=0;i<SZ;i++)
		{
			for(ll j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(ll k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(w.arr[i][k] , q.arr[k][j]));
				}
			}
		}
		// return res;
		rep(i, SZ) rep(j, SZ) q.arr[i][j] = res.arr[i][j];
	}


matrix power(matrix a, ll b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		// prll(b);
		if(b & 1)
		{
			// qwe(res, a);
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}



int main()
{
	fastio;
	cin>>n>>m;

	if(n <= m-1)
	{
		cout<<1<<endl;
		return 0;
	}

	matrix A, B;

	A.reset();
	B.reset();

	A.arr[0][0] = 1;
	A.arr[0][m-1] = 1;

	repn(i, m-1) A.arr[i][i-1] = 1;

	rep(i, m)
	{
		rep(j, m) B.arr[i][j] = 1;
	}

	B.arr[m-1][0] = 1;

	matrix An = (power(A, n-(m-1)));
	matrix Anb = An * B;
	print(Anb.arr[0][0] % MOD); 
	// ll ans =0;
	// rep(i, m) ans= (ans + Anb.arr[0][i] * B.arr[i][0])%MOD;
	// print(ans);
	// rep(i, m) rep(j, m)


	// repn(i, m) B[i-1] = m-i;

	// power(A, n);


	return 0;
}
