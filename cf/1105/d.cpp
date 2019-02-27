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

ll n, m , p;
ll sp[16];
ll ar[1024][1024];
ll dis[11][1024][1024];
ll own[1024][1024];
deque <pll> q[16];
ll ans[16];
ll mx = 10000000000;
ll cnt=0;
int check(int a, int b, int cur)
{
	if( a>=1 && a<=n && b>=1 && b<=m && dis[cur][a][b] ==mx && ar[a][b] !=-1  && own[a][b] ==0) return 1;
	return 0;
}
int main()
{
	fastio;
	cin>>n>>m>>p;
	repn(i, p) cin>>sp[i];
	rep(i, 1024) rep(j, 1024) rep(k, 11) dis[k][i][j] = mx;
	cnt = 0;
	repn(i, n)
	{
		string s; cin>>s;
		rep(j, m) 
		{
			if(s[j] == '.') ar[i][j+1] = 0, cnt++;
			else if(s[j] == '#') ar[i][j+1] = -1;
			else 
			{
				int temp = s[j] - '0';
				ar[i][j+1] = temp;
				q[temp].push_back(mp(i, j+1));
				dis[temp][i][j+1] = 0; 
			}
		}
	}

	ll a, b;

	while(cnt>0)
	{
		repn(cur, p)
		{
			ll step  = sp[cur];
			while(step--)
			{
			pii front = q[cur].front();
	// 		q[cur].pop_front();

			a = front.f+1; b = front.s;
			if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b)) , own[a][b] = cur , cnt--;

			a = front.f-1; b = front.s;
			if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b)) , own[a][b] = cur , cnt--;

			a = front.f; b = front.s + 1;
			if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b)) , own[a][b] = cur , cnt--;

			a = front.f; b = front.s -1;
			if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b)) , own[a][b] = cur , cnt--;

			}

		}
	}

	// repn(i, n)
	// {
	// 	repn(j, m) cout<<ar[i][j]<<" ";
	// 	cout<<endl;
	// }
	// repn(cur, p)
	// {
	// 	cout<<"---------------"<<endl;
	// 	repn(i, n)
	// 	{
	// 		repn(j, m) cout<<dis[cur][i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// }
	// repn(cur, p)
	// {
	// 	while(q[cur].size() > 0)
	// 	{
	// 		pii front = q[cur].front();
	// 		q[cur].pop_front();


	// 		a = front.f+1; b = front.s;
	// 		if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b));

	// 		a = front.f-1; b = front.s;
	// 		if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b));

	// 		a = front.f; b = front.s + 1;
	// 		if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b));

	// 		a = front.f; b = front.s -1;
	// 		if(check(a,b, cur)) dis[cur][a][b] = dis[cur][front.f][front.s] + (ll)1 , q[cur].push_back(mp(a,b));

	// 	}
	// }
	// cout<<"after"<<endl;
	// 	repn(cur, p)
	// {
	// 	cout<<"---------------"<<endl;
	// 	repn(i, n)
	// 	{
	// 		repn(j, m) cout<<dis[cur][i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// }

	// repn(i, n) repn(j, m)
	// {
	// 	if(ar[i][j]!=-1)
	// 	{
	// 		ll besttime = 10000000;
	// 		ll best=-1;
	// 		repn(cur, p)
	// 		{
	// 			ll curtime = (dis[cur][i][j] + sp[cur]-1)/sp[cur];
	// 			if(curtime < besttime) besttime = curtime, best = cur;
	// 		}
	// 		own[i][j] = best;
	// 		ans[best]++;
	// 	}
	// }

	repn(i, n)
		{
			repn(j, m) cout<<own[i][j]<<" ";
			cout<<endl;
		}

	printarray(ans, 1, p);


	return 0;
}
