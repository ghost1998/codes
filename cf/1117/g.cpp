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

int st2[4*N];

void build2(int node, int L, int R)
{
	if(L==R)
	{
		st2[node]=-1;
		return;
	}
	int M=(L+R)/2;
	build2(node*2, L, M);
	build2(node*2+1, M+1, R);
	st2[node]=max(st2[node*2], st2[node*2+1]);
}

int query2(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return -1;
	if(i<=L && R<=j)
		return st2[node];
	int M=(L+R)/2;
	int left=query2(node*2, L, M, i, j);
	int right=query2(node*2 + 1, M+1, R, i, j);
	return max(left, right);
}


ll n, q;
ll ar[1000010];
int main()
{
	fastio;
	cin>>n>>q;
	rep(i, n) cin>>ar[i];

	return 0;
}
