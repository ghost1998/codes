#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n, k; cin>>n>>k;
  long long ar[11];
  long long cnt[11];for(int i =0; i < 11; i++) cnt[i] = 0;
  for(int i = 0; i <k; i++) cin>>ar[i], cnt[ar[i]] = 1;
    
  return 0;
}
