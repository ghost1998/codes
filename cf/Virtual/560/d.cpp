#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int p = 1217;

void mk_hash(string &a, int* h1)
{
  h1[0] = 0;
  long long mult = 1
  for(int i = 1; i < a.size()+1; i++)
  {
    h1[i] = (h1[i-1] + (a[i-1] -'a')*mult )%p;
    mult *= p;
  }
  return;
}
long long int pow(long long a, long long b)
{
  long long x,y;
  x = a; y = b;
  long int ans = 1;
  while(y)
  {
    if(y%2==1) ans*x;
    y = y/2;
    x = x*x;
  }
  return ans;
}

int check(int *h1, int *h2, int s1, int e1, int s2, int e2)
{
  long long first , second;
  first = pow(h1[e1] - h1[s1-1], (s1-1)*(p-2));
  second = pow(h2[e2] - h2[s2-1], (s2-1)*(p-2));
  if(first == second) return 1;
  if((e1-s1)%2==1)
  {

  }

}
int main()
{
  string a,b; cin>>a>>b;
  int h1[a.size()+2];
  int h2[a.size()+2];
  mk_hash(a, h1);
  mk_hash(b, h2);
  int ans = check(h1, h2, 1, a.size(), 1, a.size());
  return 0;
}
