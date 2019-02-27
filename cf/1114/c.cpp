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

vector<pll> prime(ll  n) 
{
	vector<pll> ans; 
	ll count = 0;

    while (n%2 == 0) 
    {
    	count++; 
        n = n/2; 
    } 
    if( count> 0 )  ans.pb(mp((ll)2 , count));
  
    for (ll i = 3; i <= sqrt(n); i = i+2) 
    { 
    	count = 0;
        while (n%i == 0) 
        { 
        	count++;
            n = n/i; 
        } 
        if( count> 0 ) ans.pb(mp(i , count));

    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        ans.pb(mp((ll)n, (ll)1));
    return ans;
} 

ll hpower(ll n, ll b)
{
	ll ans = 0;
	ll a = b;
	while(1)
	{
		if(n/a ==0) break;
		else ans += n/a;

		n =  n/a;
	}
	return ans;
}

ll solve(ll n, ll b)
{
	ll ans = 1000000000000000000;
	// cout<<ans<<endl;
	// return ans;
	vector<pll> pr = prime(b);
	vll lt;
	rep(i, pr.size())
	{
		ll temp = hpower(n, pr[i].f);

		temp = temp/pr[i].s;
		// cout<<pr[i].f<<" "<<temp<<endl;

		ans = min(ans, temp);
	}
	return ans;
}


int main()
{
	fastio;
	ll n, b;

	cin>>n>>b;
	

	ll ans = solve(n, b);
	print(ans);
	return 0;
}
