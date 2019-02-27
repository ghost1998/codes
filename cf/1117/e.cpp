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

string st;

// int perm[10010][10010];
int from[10010];
string play()
{
	string original(st);
	// print("in function");
	string s1(st),s2(st),s3(st);
	string t1,t2,t3;
	rep(i, st.size())
	{
		s1[i] = 'a' + (i%26);
		s2[i] = 'a' + ((i/26)%26);
		s3[i] = 'a' + ((i/(26*26))%26);
	}
	// int temp = 'h' - 'b';
	// print(temp);
	cout<<"? "<<s1<<endl;fflush(stdout); cin>>t1;
	cout<<"? "<<s2<<endl;fflush(stdout); cin>>t2;
	cout<<"? "<<s3<<endl;fflush(stdout); cin>>t3;

	rep(i, st.size())
	{
		from[i] = (((int)(t3[i]-'a'))*26*26) + (((int)(t2[i]-'a'))*26) + (((int)(t1[i]-'a')));
		// int shift = s[i] 
		// rep(j, st.size())
		// {
		// 	if(t1[i] == s1[j]) perm[i][j]++;
		// 	if(t2[i] == s2[j]) perm[i][j]++;
		// 	if(t3[i] == s3[j]) perm[i][j]++;
		// 	if(perm[i][j] == 3) from[i] = j;
		// }
	}

	rep(i, st.size())
	{
		original[from[i]] = st[i];

	}
	cout<<"! "<<original<<endl;
	fflush(stdout);
	// cout<<s1<<" "<<s2<<" "<<s3<<endl;


	return original;
}



int main()
{
	fastio;
	cin>>st;
	while(true)
	{
		string ans = play();
		// cout<<"!"<<" "<<ans<<endl;fflush(stdout);
		return 0;

	}
	return 0;
}
