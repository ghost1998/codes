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

ll ans;
ll product = 1;
ll ar[500010];
ll n;

void solve(int idx, ll cur_product, ll cur_sum)
{
	if(cur_product == 1 && idx == n )
	{
		ans = min(cur_sum, ans);
		return ;
	}

	if(idx >=n) return;

	if(cur_product == 1)
	{
		ans = min(ans, cur_sum + (n-idx) );
		return ;
	}

	if(cur_sum > ans) return ;

	if(idx<n)
	{
		repn(i, 100) if(cur_product%i == 0) solve(idx+1 , (cur_product/(ll)i), cur_sum + i);
		return ;
	}
	return ;

}

int main()
{
	fastio;
	cin>>n;
	rep(i, n) cin>>ar[i] , product*=ar[i] , ans+=ar[i];

	solve(0, product, (ll)0);
	print(ans);

	return 0;
}
