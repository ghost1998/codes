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



int main()
{
	fastio;
	ll q; cin>>q;
	ll n;

	set<ll> st;
	repn(i, 29) st.insert(((ll) (1<<i)-1) );
	map<ll, ll> mp;

	mp[67108863]=22369621;
mp[33554431]=1082401;
mp[16777215]=5592405;
mp[8388607]=178481;
mp[4194303]=1398101;
mp[2097151]=299593;
mp[1048575]=349525;
mp[524287]=1;
mp[262143]=87381;
mp[131071]=1;
mp[65535]=21845;
mp[32767]=4681;
mp[16383]=5461;
mp[8191]=1;
mp[4095]=1365;
mp[2047]=89;
mp[1023]=341;
mp[511]=73;
mp[255]=85;
mp[127]=1;
mp[63]=21;
mp[31]=1;
mp[15]=5;
mp[7]=1;
mp[3]=1;
mp[1]=1;
mp[0]=1;

	while(q--)
	{
		cin>>n;
		if(mp.find(n) == mp.end())
		{
			ll ans = (((ll)1)<<(1 + (int)log2(n))) - 1;
			print(ans);
		}
		else
		{
			ll temp = n;
			ll ans=0;
			ans = mp[n];
			print(ans);
		}


	}

	return 0;
}
