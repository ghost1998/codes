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


ll play()
{
	// print("in function");
	ll x =1, y=2;
	char res;
	while(true)
	{
		// print("in loop")
		// print(x);
		cout<<"? "<<x<<" "<<y<<endl;
		// cout<<"?"<<" "<<x<<" "<<y;
		fflush(stdout);
		cin>>res;
		if(res=='y') x<<=1 , y<<=1;
		else break; 
	}
	// cout<<"Before Bin search : " <<x<<" "<<y<<endl;
	while(x<y)
	{
		ll mid = 1+ x + (y-x)/2 ;
		cout<<"?"<<" "<<x<<" "<<mid<<endl;
		fflush(stdout);
		cin>>res;
		if(res=='y') x = mid;
		else y = mid-1;
	}
	if(x==1)
	{
		cout<<"? "<<2<<" "<<3<<endl;
		fflush(stdout);
		cin>>res;
		if(res=='y') return 2;
		return 1;
	}
	else return x+1;
}


int main()
{
	fastio;
	string s;
	ll x,y, ans;
	while(true)
	{
		cin>>s;
		if(s=="end") break;
		else if(s=="start")
		{
			// cout<<"here"<<endl;
			ans = play();
			cout<<"!"<<" "<<ans<<endl;fflush(stdout);
		}
		else 
		{
			return 0;
		}
	}
	return 0;
}
