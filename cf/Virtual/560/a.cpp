#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int n; cin>>n;
  long int flag = 1;
  long int temp;
  for(int i =0; i < n ; i ++)
  {
    cin>>temp;
    if(temp==1) flag = -1;
  }
  std::cout << flag << '\n';
  return 0;
}
