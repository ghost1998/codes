#include <bits/stdc++.h>
using namespace std;


int main()
{
  long int t; cin>>t;
  long int ix=1;
  while(t--)
  {
    long int, n, q; cin>>n>>q;
    long int x1,x2,a1,b1,c1,m1; cin>> x1>>x2>>a1>>b1>>c1>>m1;
    long int y1,y2,a2,b2,c2,m2; cin>> y1>>y2>>a2>>b2>>c2>>m2;
    long int z1,z2,a3,b3,c3,m3; cin>> z1>>z2>>a3>>b3>>c3>>m3;

    long int xi,yi;
    long int xi1=x2,yi1=y2;
    long int xi2=x1,yi2=y1;

    vector<pair<long int, long int> > v;
    map<long int, long int> q;

    map<long int, int> pre;

    v.push_back(make_pair(min(x1,y1), max(x1,y1) ));

    v.push_back(make_pair(min(x2,y2), max(x2,y2)));
    v.push_back(make_pair());

    for(int i=2; i<n;i++)
    {
      xi = (a1*xi1 + b1*xi2 + c1)%m1;
      yi = (a2*yi1 + b2*yi2 + c2)%m2;
      v.push_back(make_pair(min(xi,yi), max(xi,yi)));

      if(pre.find(max(xi,yi)) == pre.end())
      {
        pre.insert(make_pair(max(xi,yi), 1));
      }
      else pre[max(xi,yi)]++;

      if(pre.find(min(xi,yi)-1) == pre.end())
      {
        pre.insert(make_pair(min(xi,yi)-1, -1));
      }
      else pre[min(xi,yi)--]--;


      xi2 = xi1; yi2 = yi1;
      xi1 = x1; yi1 = yi;
    }

    q.insert(make_pair(z1+1, 1));
    q.insert(make_pair(z2+1, 2));

    long int zi1=z2, zi2 = z1;
    for(int i=2; i<q;i++)
    {
      zi = (a3*zi1 + b3*zi2 + c3)%m3;
      q.insert(make_pair(zi+1, i+1));
      zi2=zi1;
      zi1 = zi;
    }

    long long int ans=0;

    for(map<long int, long int> :: reverse_iterator it = q.rbegin(); it!=q.rend(); ++it)
    {
      
    }




    std::cout << "Case #"<<(ix++)<<": ";
    std::cout << ans << '\n';
  }
  return 0;
}
