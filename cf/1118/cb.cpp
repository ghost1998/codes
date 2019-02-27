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

ll n;
ll ar[400];
ll mat[30][30];
ll pre[1010];

int main()
{
	fastio;
	cin>>n;
	rep(i, n*n) cin>>ar[i] , pre[ar[i]]++;

	rep(i, 30) rep(j, 30) mat[i][j] = -1;

	int marker = 1;
	if(n%2==0)
	{
		marker = 1;
		rep(i, n) rep(j, n)
		{
			if(marker >= 1200) break;

			if(mat[i][j] == -1)
			{
				if(marker >= 1200) break;
				while(pre[marker] == 0 && marker <=1200) marker++;
				if(pre[marker]%4 ==0)
				{
					pre[marker] -=4;
					mat[i][j] = marker;
					mat[n-1-i][j] = marker;
					mat[i][n-1-j] = marker;
					mat[n-1-i][n-1-j] = marker;
				}
				else marker++;

			}
			
			
		}
	}

	else
	{
		marker = 1;
		rep(i, n) rep(j, n)
		{
			if(marker >= 1200) break;

			if(mat[i][j] == -1)
			{
				if(i== n/2  || j==n/2)
				{

				}
				else
				{
					while(pre[marker] <4 && marker<= 1200) marker++;
					if(pre[marker]>= 4)
					{
						// print(marker);
						// cout<<"here"<<endl;
						pre[marker] -=4;
						mat[i][j] = marker;
						mat[n-1-i][j] = marker;
						mat[i][n-1-j] = marker;
						mat[n-1-i][n-1-j] = marker;
					}
					else marker++;
				}
			}
		}

			marker = 1;

		rep(i, n)
		{

			if(i!= n/2 && mat[i][n/2] == -1)
			{
				if(marker >= 1200) break;
			while( pre[marker] <2 && marker<1200) marker++;
			if(pre[marker] >=2)
			{
				pre[marker] -= 2;
				mat[i][n/2] = marker; 
				mat[n-1 -i][n/2] = marker; 
			}}
		}


		marker = 1;

		rep(i, n)
		{

			if(i!= n/2 && mat[n/2][i] == -1)
			{
				if(marker >= 1200) break;
			while( pre[marker] <2 && marker<1200) marker++;
			if(pre[marker] >=2)
			{
				pre[marker] -= 2;
				mat[n/2][i] = marker; 
				mat[n/2][n-1 -i] = marker; 
			}}
		}


		marker = 1;

		while(pre[marker] == 0 && marker <=1200 ) marker++;
		if(pre[marker] > 0) mat[n/2][n/1] = marker;



	}

	ll pos=1;

	rep(i, n) rep(j, n) if(mat[i][j] == -1){ print(i) ; print(j); pos = 0; break;}

	if(pos == 0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		rep(i, n)
		{
			rep(j, n) cout<<mat[i][j]<<" ";
			cout<<"\n"<<endl;
		}

	}

	return 0;
}
