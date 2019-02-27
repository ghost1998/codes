#include <bits/stdc++.h>
using namespace std;
int main()
{
  long int t; cin>>t;
  while(t--)
  {
    int n, m;
    cin>>n>>m;
    long int a[n+1]; long int b[m+1];
    long int asum=0, bsum=0;
    for(int i=0; i<n;i++) cin>>a[i], asum+=a[i];
    for(int i=0; i<m;i++) cin>>b[i], bsum+=b[i];

    if(asum!=bsum || m!=n)
    {
      std::cout << "Alice" << '\n';
    }
    else
    {
      sort(a, a+m);
      sort(b, b+n);

      int flag =0;

      for(int i=0; i<m;i++) if(a[i] != b[i]) flag=1;

      if(flag==1) std::cout << "Alice" << '\n';
      else std::cout << "Bob" << '\n';


    }
  }
  return 0;
}



.#. -> #..
#.. -> .#.

#####.     # ##..##

..#.##.. -> .#..##..
...###... -> ...##..#.
....####.... -> #.....#.#.#.
..####.... -> ##....#.#.

....####..##.... -> ####.....#....#.
....####..##.... -> ....####..##....


#..#....#.#.


....####..

....###.#...
....###..#..
....##.#.#..
....##.#..#.
....##..#.#.
....#.#.#.#.
...#..#.#.#.
..#...#.#.#.
.#....#.#.#.
#.....#.#.#.
#....#..#.#.
