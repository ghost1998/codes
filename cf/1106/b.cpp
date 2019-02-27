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

ll n, m;
ll a[100010];
ll c[100010];
ll t, d;
ll cur;
ll remaining, ans;
vector< pll> vec;

void solve(ll &t, ll &d, ll &total)
{
	// print(t);
	ll anst=0;
	if(a[t]>d)
	{
		a[t] -= d;
		anst += (c[t] * d);
		d=0;
	}
	else
	{
		anst += (c[t] * a[t]);
		d = d - a[t];
		a[t]=0;
	}

	total += anst;
}
int main()
{
	fastio;
	cin>>n>>m;
	repn(i, n) cin>>a[i];
	repn(i, n) cin>>c[i], vec.pb(mp(c[i], (ll)i));
	sort(vec.begin(), vec.end());
	// cur = vec[0].s;
	cur =0;
	ll flag =0;
	rep(i, m)
	{
		// cout<<"----------"<<endl;
		ans =0;
		cin>>t>>d;
		if(flag==1)
		{
			ans =0;
			print(ans);
			continue;
		}
		ans = 0;
		solve(t, d, ans);
		// print(ans);
		while(d>0)
		{
			while(vec.size() >0 && a[vec[0].s] <=0) vec.erase(vec.begin());
			if(vec.size() ==0)
			{
				ans = 0;
				flag = 1;
				break;
			}
			t = vec[0].s;
			solve(t, d, ans);
		}
		print(ans);

	}
	return 0;
}
