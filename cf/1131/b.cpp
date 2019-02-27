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


set<ll> st;



ll solve(ll p1, ll p2, ll c1,ll c2)
{
	// ll temp = 0;
	// ll m1 = max(p1, p2);
	// ll m2 = min(c1, c2);
	// if(m2==m1)
	// {
	// 	if(st.find(m2) == st.end()) temp = 0;
	// 	else temp = 1;
	// 	st.insert(m2);
	// }
	// else if(m2 > m1)
	// {
	// 	temp = m2-m1+1;
	// 	if(st.find(m2) != st.end()) temp--; 
	// 	if(st.find(m1) != st.end()) temp--; 
	// 	st.insert(m1);
	// 	st.insert(m2);
	// }

	ll temp = 0;
	temp += max(((min(c1, c2) -max(p1, p2)) + 1), (ll)0);
	if(temp>0)
	{
		if(c1==c2) temp--;
	}
	// cout<<p1<<" "<<p2<<" "<<c1<<" "<<c2<<" "<<endl;
	// print(temp);
	// print(((min(p2, c2) -max(p1, c1)) + 1));
	return temp;
}

int main()
{
	fastio;
	ll n; cin>>n;
	ll p1,p2,c1,c2;
	p1=0;p2=0;
	ll ans = 0;
	rep(i, n)
	{
		cin>>c1>>c2;
		// if(c1==p1 && c2==p2) continue;
		ans+=solve(p1,p2,c1,c2);
		p1 = c1; p2 = c2;
		// print(ans);
	}
	if(c1 == c2) ans++;
	ans = max(ans, (ll)1);
	print(ans);
	return 0;
}
