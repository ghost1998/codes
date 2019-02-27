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

ll n, m;
ll ar[1000010];
ll dp[1000010][3][3];
ll ans =0;
int main()
{
	fastio;
	cin>>n>>m;
	ll temp;
	rep(i, n) cin>>temp, ar[temp]++;

	repn(i, m)
	{
		// ans += (ar[i]/3);
		// if(ar[i]%)

		rep(j, 3) rep(k, 3) rep(l, 3)
		{ 

			if(ar[i]>=l) dp[i][0][l] = max(dp[i][0][l], (ar[i]-l)/3);
			ans  = max(ans, dp[i][0][l]);


			if(ar[i]>=l && dp[i-1][j][k] > 0) dp[i][k- min(l, min(j, k))][l - min(l, min(j, k))] =   max((dp[i-1][j][k] + (((ar[i])-l)/3) + min(l, min(j, k))), (dp[i][k- min(l, min(j, k))][l - min(l, min(j, k))]));
			ans = max(dp[i][k- min(l, min(j, k))][l - min(l, min(j, k))] , ans);
			// if(ans==2) cout<<j<<" "<<k<<l<<endl;
		}


		// dp[i][0][2] = max(dp[i][0][2] , dp[i-1][0][0]+ ((ar[i]-(2))/3)); 
		// dp[i][0][1] = max(dp[i][0][1] , dp[i-1][0][0]+ ((ar[i]-(1))/3)); 
		// dp[i][0][0] = max(dp[i][0][0] , dp[i-1][0][0]+ ((ar[i]-(0))/3));


		// dp[i][1][2] = max(dp[i][1][2] , dp[i-1][0][1]+ ((ar[i]-(2))/3)); 
		// dp[i][1][1] = max(dp[i][1][1] , dp[i-1][0][1]+ ((ar[i]-(1))/3)); 
		// dp[i][1][0] = max(dp[i][1][0] , dp[i-1][0][1]+ ((ar[i]-(0))/3));

		// dp[i][2][2] = max(dp[i][2][2] , dp[i-1][0][2]+ ((ar[i]-(2))/3)); 
		// dp[i][2][1] = max(dp[i][2][1] , dp[i-1][0][2]+ ((ar[i]-(1))/3)); 
		// dp[i][2][0] = max(dp[i][2][0] , dp[i-1][0][2]+ ((ar[i]-(0))/3)); 


		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
	
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
	
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 
		// dp[i][][] = max(dp[i][][] , dp[i-1][][]+ ((ar[i]-())/3)); 

	}
	// repn(i, m)
	// {
	// 	cout<<endl;
	// 	cout<<endl;
	// 	cout<<i<<endl;
	// 	rep(j,3) 
	// 	{
	// 		rep(k, 3)
	// 		{
	// 						cout<<dp[i][j][k]<<" ";

	// 		}
	// 		cout<<endl;
	// 	}
	// }
	print(ans);
	return 0;
}
