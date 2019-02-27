#include <bits/stdc++.h>
using namespace std;

double err = 1e-7;

double check(vector<pair<int, int> > &v, double mid, double x_point)
{
  // coordinate = (x_point, mid)
  // radius = mid

  int n = v.size();
  int flag = 1;
  for(int i=0;i<n;i++)
  {
    double distance =  ((x_point-v[i].first) * (x_point-v[i].first)) + ((mid-v[i].second) *  (mid-v[i].second));
    if( distance > mid*mid ) flag = 0;
  }

  return flag;
}

double search(vector<pair<int, int> > &v, double lo, double hi, double x_point)
{
  if((hi-lo) < err) return hi;

  // double mid = (lo+hi)/2;
  double mid = sqrt(lo*hi);
  int sat = check(v, mid, x_point);

  if(sat == 1) return search(v, lo, mid, x_point);
  else search(v, mid, hi, x_point);
}

int main()
{
  int n;
  cin>>n;
  vector<pair<int, int> > v;
  long int x_sum =0;
  // long int mx,mn;
  // mx = -1 * 1e+7;
  // mn = 1e+7;
  for(int i=0;i<n;i++)
  {
    int t1,t2;
    cin>>t1>>t2;
    x_sum+=t1;
    // mx = max(max, t2);
    // mn = min(mn, t2);
    v.push_back(make_pair(t1,t2));
  }

  // if(mx* mn <0)
  // {
  //   std::cout << "-1" << '\n';
  //   return 0;
  // }
  double x_point = (x_sum*1.0)/n;
  double ans = search(v, 1e-7, 1e+7, x_point);
  if(ans > 1020000) std::cout << "-1" << '\n';
  else std::cout << ans << '\n';
  return 0;
}
