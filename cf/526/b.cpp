#include <bits/stdc++.h>
using namespace std;
long long int bsearch(vector<long long int> &v, long long int lo, long long int hi, long long int s)
{
  // cout<<lo <<" "<<hi<<endl;
  if(lo == hi) return lo;
  int mid =  (hi+lo)/2 + 1;
  long long int sum= 0;
  for(int i = 0 ; i < v.size() ; i ++) if(v[i] > mid) sum += (v[i] -mid);

  if(sum>=s)
  {
    return bsearch(v, mid, hi, s);
  }
  else
  {
    return bsearch(v, lo, mid-1, s);
  }
}
int main()
{
  long long int n, s; cin>>n>>s;
  long long int sum=0;
  vector<long long int> v(n , 0);
  for(int i = 0; i <n; i++) cin>>v[i], sum+=v[i];
  long long int ans = s>sum ? -1 : bsearch(v, 0, sum, s);
  cout<<ans<<endl;
  return 0;
}
