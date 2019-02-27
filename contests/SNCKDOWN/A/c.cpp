#include <bits/stdc++.h>
using namespace std;

int valid(int x, int y, int n, int m)
{
  if(x>=0 && x<n && y>=0 && y<m) return 1;
  return 0;
}

int main()
{
  int t; cin>>t;

  while(t--)
  {
    int n, m; cin>>n>>m;
    string temp;

    std::vector<string> mat;
    for(int i=0; i<n;i++) cin>>temp, mat.push_back(temp);
    int dp[n][m][n+m][4];
    int ans[n+m];
    for(int i=0; i<n+m;i++) ans[i]=0;



    for(int i=0; i<n;i++) for(int j=0; j<m;j++) for(int l=0; l<4; l++) dp[i][j][0][l]= mat[i][j]=='1'?1:0;



    for(int k=1; k<n+m-2; k++)
    {
      for(int i=0; i<n;i++)
      {
        for(int j=0; j<m;j++)
        {
          dp[i][j][k][0]=0;
          dp[i][j][k][1]=0;
          dp[i][j][k][2]=0;
          dp[i][j][k][3]=0;
          // dp[i][j][k][0] = dp[i-1][j+1][k-2][0] + (mat[i][j+k]=='1'?1:0) + (mat[i-k][j]=='1'?1:0);
          if(valid(i-1, j+1, n , m) && k>=2) dp[i][j][k][0] += dp[i-1][j+1][k-2][0];
          if(valid(i, j+k, n, m)) dp[i][j][k][0] +=(mat[i][j+k]=='1'?1:0);
          if(valid(i-k, j, n, m)) dp[i][j][k][0] += (mat[i-k][j]=='1'?1:0);


          // dp[i][j][k][1] = dp[i-1][j-1][k-2][0] + (mat[i][j-k]=='1'?1:0) + (mat[i-k][j]=='1'?1:0);
          if(valid(i-1, j-1, n , m) && k>=2) dp[i][j][k][1] += dp[i-1][j-1][k-2][1];
          if(valid(i, j-k, n, m)) dp[i][j][k][1] +=(mat[i][j-k]=='1'?1:0);
          if(valid(i-k, j, n, m)) dp[i][j][k][1] += (mat[i-k][j]=='1'?1:0);


          // dp[i][j][k][2] = dp[i+1][j-1][k-2][0] + (mat[i][j-k]=='1'?1:0) + (mat[i+k][j]=='1'?1:0);
          if(valid(i+1, j-1, n , m) && k>=2) dp[i][j][k][2] += dp[i+1][j-1][k-2][2];
          if(valid(i, j-k, n, m)) dp[i][j][k][2] +=(mat[i][j-k]=='1'?1:0);
          if(valid(i+k, j, n, m)) dp[i][j][k][2] += (mat[i+k][j]=='1'?1:0);




          // dp[i][j][k][3] = dp[i+1][j+1][k-2][0] + (mat[i][j+k]=='1'?1:0) + (mat[i+k][j]=='1'?1:0);
          if(valid(i+1, j+1, n , m) && k>=2) dp[i][j][k][3] += dp[i+1][j+1][k-2][3];
          if(valid(i, j+k, n, m)) dp[i][j][k][3] +=(mat[i][j+k]=='1'?1:0);
          if(valid(i+k, j, n, m)) dp[i][j][k][3] += (mat[i+k][j]=='1'?1:0);

          long int temp = dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2] + dp[i][j][k][3]
                            - ((valid(i, j+k, n, m) && mat[i][j+k]=='1')?1:0)
                            - ((valid(i, j-k, n, m) && mat[i][j-k]=='1')?1:0)
                            - ((valid(i+k, j, n, m) && mat[i+k][j]=='1')?1:0)
                            - ((valid(i-k, j, n, m) && mat[i-k][j]=='1')?1:0) ;

          if(mat[i][j] =='1') ans[k] +=temp;



        }
      }

      // std::cout  << '\n';
      // std::cout << k << '\n';
      // for(int i=0; i<n;i++)
      // {
      //   for(int j=0; j<m;j++) std::cout << dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2] + dp[i][j][k][3]
      //                   - ((valid(i, j+k, n, m) && mat[i][j+k]=='1')?1:0)
      //                   - ((valid(i, j-k, n, m) && mat[i][j-k]=='1')?1:0)
      //                   - ((valid(i+k, j, n, m) && mat[i+k][j]=='1')?1:0)
      //                   - ((valid(i-k, j, n, m) && mat[i-k][j]=='1')?1:0)
      //                    << ' ';
      //   std::cout  << '\n';
      // }
      // std::cout  << '\n';
      // std::cout << "print ends" << '\n';
    }
    for(int i=1; i<=n+m-2; i++) std::cout << ans[i]/2 << ' ';
    std::cout  << '\n';
  }
  return 0;
}
