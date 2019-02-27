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
	string a,b; cin>>a>>b;
	ll a1=0, b1=0;

	if(a.size() != b.size())
	{
		cout<<"No"<<endl;
		return 0;
	}
	ll flag = 0;
	rep(i, a.size()) 
	{
		if( !((a[i]=='a' || a[i]=='e' || a[i]=='i' ||a[i]=='o' ||a[i]=='u'))  &&  ((b[i]=='a' || b[i]=='e' || b[i]=='i' ||b[i]=='o' ||b[i]=='u')) ) 
			flag = 1;
		if( ((a[i]=='a' || a[i]=='e' || a[i]=='i' ||a[i]=='o' ||a[i]=='u'))  &&  !((b[i]=='a' || b[i]=='e' || b[i]=='i' ||b[i]=='o' ||b[i]=='u')) ) 
			flag = 1;
	}
	// rep(i, a.size()) if(a[i]=='a' || a[i]=='e' || a[i]=='i' ||a[i]=='o' ||a[i]=='u') a1++;
	// rep(i, b.size()) if(b[i]=='a' || b[i]=='e' || b[i]=='i' ||b[i]=='o' ||b[i]=='u') b1++;

	if(flag==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
