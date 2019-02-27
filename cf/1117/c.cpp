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


ll xa,ya,xb,yb;
string s;
ll sz;

ll wx, wy;


int valid(ll val)
{
	ll windx=0, windy = 0;
	windx = xa + (val/sz) * wx;
	windy = ya + (val/sz) * wy;
	
	rep(i, val%sz)
	{
		if(s[i] == 'U') windy++;
		else if(s[i] == 'D') windy--;
		else if(s[i] == 'L') windx--;
		else if(s[i] == 'R') windx++;
	}

	if((abs(windx -xb) + abs(windy -yb)) <= val) return 1;
	else return 0;



}

ll binsearch(ll lo, ll hi)
{
	if(lo == hi) return lo;

	ll mid = lo + (hi-lo)/2 ;

	if(valid(mid)) return binsearch(lo, mid);
	else return binsearch(mid+1 , hi);
}
int main()
{
	fastio;
	cin>>(xa)>>(ya);
	cin>>xb>>yb;
	cin>>sz;
	cin>>s;

	rep(i, s.size())
	{
		if(s[i] == 'U') wy++;
		else if(s[i] == 'D') wy--;
		else if(s[i] == 'L') wx--;
		else if(s[i] == 'R') wx++;
	}

	ll ans = binsearch(0, (ll)2000000000000100);

	
	if(valid(ans) == 0) ans = -1; 
	print(ans);
	return 0;

}
