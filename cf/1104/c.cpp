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
	string s; cin>>s;
	int flag1=0, flag2=0;
	vector<pii> ans;
	rep(i, s.size())
	{
		if(s[i] == '0') //vertical
		{
			if(flag1==0) ans.pb(mp(1,1)) , flag1 = 1;
			else ans.pb(mp(3,1)) , flag1=0;
		}
		else 
		{
			if(flag2==0) ans.pb(mp(4,3)), flag2=1;
			else ans.pb(mp(4,1)), flag2 =0;
		}
	}

	rep(i, ans.size()) cout<<ans[i].f<<" "<<ans[i].s<<endl;
	return 0;
}
