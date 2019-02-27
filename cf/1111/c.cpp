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


ll n, k , a, b;
ll pre[35];
map<ll, int> m;


ll solve(ll start, ll end)
{
	ll ans1=0;
	ll ans2=0;

	auto it1 = lower_bound(end);
	auto it2 = lower_bound(start-1);
	ll num= (it1->s) - (it2->s);
	if(num==0) ans1 = a;
	else ans1 = b*num* (1<<(end-start)); 

}
int main()
{
	fastio;

	cin>>n>>k>>a>>b;
	ll ar[k+2];

	rep(i, k) 
	{
		cin>>ar[i] ;
		m[ar[i]]++;
	}

	ll prev =0;
	for(auto it= m.begin() ; it!=m.end(); it++)
	{
		it->s += prev;
		prev = it->s;
	}
	ll ans = solve(1, n);

	return 0;
}
