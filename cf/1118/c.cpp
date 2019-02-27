#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);



typedef int ll;
// typedef long long ll;
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

	ll n;
ll ar[400];
ll mat[30][30];
ll pre[1101];


int main()
{

	// fastio;
	cin>>n;
	// rep(i, 1200) pre[i]=0;

	rep(i, n*n) cin>>ar[i] , pre[ar[i]]++;

	rep(i, 30) rep(j, 30) mat[i][j] = -1;

	// printarray(pre, 1, 10);

	if(n%2 == 0)
	{
		rep(i, n) rep(j, n)
		{
				if(mat[i][j] != -1) continue;

			if(mat[i][j] == -1)
			{
				if(mat[i][j] != -1) continue;

				repn(k, 1100)
				{
					if(mat[i][j] != -1) break;

					if(pre[k] >=4)
					{
						// cout<<"Here : "<<k<<endl;
						// cout<<i<<" "<<j<<endl;
						mat[i][j] = k;
						mat[n-1-i][n-1-j] = k;
						mat[n-1-i][j] = k;
						mat[i][n-1-j] = k;
						pre[k] -=4;
						break;
					}
				}

			}
		}
	}

	else
	{
		rep(i, n) rep(j, n)
		{
			if(mat[i][j] != -1) continue;

			if(i==n/2 || j==n/2)
			{

			}
			else
			{
				if(mat[i][j] == -1)
				{
			if(mat[i][j] != -1) continue;

					repn(k, 1100)
					{

						if(pre[k] >=4 && mat[i][j] == -1)
						{
						// cout<<"Here : "<<k<<endl;
						// cout<<i<<" "<<j<<endl;
							mat[i][j] = k;
							mat[n-1-i][n-1-j] = k;
							mat[n-1-i][j] = k;
							mat[i][n-1-j] = k;
							pre[k] -=4;
							break;
						}
					}

				}	
			}
		}

		rep(i, n) rep(j, n)
		{

			if(i==n/2 && j==n/2)
			{

			}
			else if(i==n/2 || j==n/2)
			{
				if(mat[i][j] == -1)
				{
					if(mat[i][j] != -1) continue;

					repn(k, 1100)
					{
						if(mat[i][j] != -1) break;

						if(pre[k] >=2 && mat[i][j] == -1)
						{
						// cout<<"Here : "<<k<<endl;
						// cout<<i<<" "<<j<<endl;
							mat[i][j] = k;
							mat[n-1-i][n-1-j] = k;
							mat[n-1-i][j] = k;
							mat[i][n-1-j] = k;
							pre[k] -=2;
							break;
						}
					}

				}	
			}
		}

		repn(k, 1100)
		{
			if(pre[k] >= 1)
			{
				mat[n/2][n/2] = k;
				pre[k]--;
				break;
			}
		}



	}

	ll pos = 1;
	rep(i, n) rep(j, n) if(mat[i][j] == -1){ /*print(i) ; print(j); */ pos = 0; break;}

	if(pos == 0)
	{
		cout<<"NO";
		cout<<endl;
	}
	else
	{
		cout<<"YES\n";
		rep(i, n)
		{
			// printarray(mat[i], 0, n-1)
			rep(j, n-1) cout<<mat[i][j]<<" "; 
			cout<<mat[i][n-1];
			cout<<endl;
		}

	}

	return 0;
}
