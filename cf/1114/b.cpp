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


ll n, m, k;
ll ar[1000010];
ll temp[1000010];
ll marker[1000010];
ll sum = 0;
int main()
{
	fastio;
	cin>>n>>m>>k;
	rep(i, n) cin>>ar[i] , temp[i] = ar[i];
	sort(temp, temp+n);
	ll num = temp[n-(m*k)];

	rep(i, n) 
	{
		if(ar[i] >= num) marker[i] = 1;
	}

	ll cnt = 0;

	for(int i = n-(m*k) ; i <n; i++) if(temp[i]== num) cnt ++;
	ll j = 0;
	ll count = 0;
	ll part = 0;
	vll ans;
	// print(cnt);
	// print(num);
	rep(i, n)
	{


		if(marker[i] == 1) 
			{
				if(ar[i] == num && cnt > 0)
				{
					// cout<<"----"<<endl;
					cnt--;
					count++;sum+=ar[i];

				}
				else  if (ar[i] > num) { count++;sum+=ar[i];}
			}



		if(count == m)
		{
			ans.pb(i);
			count = 0;
		}

		if(ans.size() == k) break;


	}
	print(sum);
	rep(i, k-1) cout<<(1 + ans[i])<<" ";
	cout<<endl;
	return 0;
}
