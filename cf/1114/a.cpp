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


ll g, p, r;
int flag;

void call()
{
	if(flag==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return ;
}
int main()
{
	fastio;
	ll x, y, z, a, b, c;
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	flag = 1;

	if(a<x)
	{
		flag = 0;
		call();
		return 0;
	}
	a -= x;
	if((a+b) <y)
	{
		flag = 0;
		call();
		return 0;
	}
	b -= (y-a);
	a = 0;

	if((a+b+c) < z)
		{
		flag = 0;
		call();
		return 0;
	}

	{
		flag = 1;
		call();
		return 0;
	}





	return 0;
}
