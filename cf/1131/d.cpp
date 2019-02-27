#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


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
#define print(x) cout<<x<<endl;
#define printarray(a, start, end) for(int i=start; i<=end; i++) cout<<a[i]<<" "; cout<<endl;

int par[150010];
int leftmost[150010];
int rightmost[150010];
int lt[150010];
int rt[150010];

int root(int v) {return par[v] < 0 ? v : (par[v] = root(par[v]));}

void merge(int x,int y)
{
	if((x = root(x)) == (y = root(y))) return;
	if(par[y] < par[x])	 swap(x, y);
	par[x] += par[y];
	par[y] = x;
	rt[rightmost[x]] = leftmost[y];
	lt[leftmost[y]] = rightmost[x];
	rightmost[x] = rightmost[y];
}


int main()
{
	fastio;
	ll n; cin>>n;
	ll a,b;
	rep(i, n+2) par[i] = -1 , leftmost[i] = i, rightmost[i] = i, lt[i] = -1, rt[i] = -1;

	rep(i, n-1)
	{
		cin>>a>>b;
		if(root(a) == root(b))
		{
			cout<<"same"<<endl;
		}
		merge(a,b);

	}

	// repn(i, n)
	// {
	// 	cout<<i<<" "<<root(i)<<" "<<leftmost[i]<<" "<<rightmost[i]<<" "<<lt[i]<<" "<<rt[i]<<endl;
	// }

	// int rt = root(1);
	int cur = root(1);
	cout<<cur<<" ";
	while(rt[cur] != -1)
	{
		cout<<rt[cur]<<" ";
		cur = rt[cur];
	}
	cout<<endl;

	return 0;
}
