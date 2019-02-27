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

ll n;
vector<string> vs;

vll solve(int idx)
{

	vll ans(26, 0);
	if(idx==0)
	{
		rep(i, vs[idx].size()) ans[vs[idx][i] - 'a']++;

		return ans;
	}

	vll prev = solve(n-2);
	ll st=0;
	int ix=0;
	while(vs[idx][ix] == vs[idx][0]) ix++, st++;

	ll ed=0;
	ll ix=0;
	while(vs[idx][ix] == vs[idx][vs[idx].size()-1]) ix--, st++;

	if(st==vs[idx].size())
	{
		ans[vs[idx][0]] = prev[vs[idx][0]] + (prev[vs[idx][0]]+1) * (vs[idx].size()); 
	}
	else
	{
		if(vs[idx][0] == vs[idx][vs[idx].size()-1])
	}
}
int main()
{
	fastio;
	cin>>n;
	string s;
	rep(i, n) cin>>s , vs.pb(s);

	vll ans = solve(n-1);

	return 0;
}
