#include <bits/stdc++.h>
using namespace std;
int mat[1010][1010];

void helper(int n, int m)
{
  for(int i =1; i<n-1;i++)
  {
    for(int j =1; j<m-1;j++)
    {
      if(mat[i+1][j+1] !=0 && mat[i+1][j] !=0 && mat[i+1][j-1] !=0 && mat[i-1][j+1] !=0
        && mat[i-1][j] !=0 && mat[i-1][j-1] !=0 && mat[i][j+1]!=0 && mat[i][j-1]!=0)
        {
          mat[i+1][j+1] = 2;
          mat[i+1][j] = 2;
          mat[i+1][j-1] = 2;
          mat[i-1][j+1] = 2;
          mat[i-1][j] = 2;
          mat[i-1][j-1] = 2;
          mat[i][j+1] = 2;
          mat[i][j-1] = 2;

        }
    }
  }
  return;
}
int main()
{
  int n, m;
  cin>>n>>m;
  for(int i =0; i<n;i++)
  {
    string s;
    cin>>s;
    for(int j =0; j<m;j++)
    {
      mat[i][j] = s[j]=='.' ? 0 : 1;
      // std::cout << mat[i][j];
    }
    // std::cout << '\n';

  }

  helper(n, m);
  int flag = 1;
  for(int i =0; i<n;i++) for(int j =0; j<m;j++) if(mat[i][j] == 1) flag =0;
  if(flag) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
  return 0;
}
