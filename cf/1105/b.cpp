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


ll n, k;
string s;

ll solve(char x, string &s)
{
	ll i=0;
	ll j;
	ll ans = 0;
	while(i<n)
	{
		if(s[i] != x) {i++; continue;}
		j = i;
		while(j-i < k-1 && s[j] == x) { j++;};
		if(j-i==k-1 && s[j] == x) ans++;
		i = j+1;
		// print(i);

	}
	return ans;

}


// ll solve(char x, string &s)
// {
// 	ll i, j, ans, temp;
// 	ans = 0;
// 	i = 0;
// 	while(i+k-1 < s.size())
// 	{
// 		if(s[i] != x) continue
// 		j = i;
// 		while(j-i <= k-1 &&)

// 	}
// }
int main()
{
	fastio;
	cin>>n>>k;
	cin>>s;
	// rep(it, 26) {char x = 'a' + it ;  cout<<x<<endl;}
	ll ans = 0;
	rep(it, 26)
	{


		char x = 'a' + it ;

		// cout<<x<<endl;
		ll temp = solve(x, s);
		ans = max(temp, ans);

	}
	print(ans);

	return 0;
}
