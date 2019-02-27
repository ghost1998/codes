// C++ program to find diameter of a binary tree
// using DFS.
#include <iostream>
#include <limits.h>
#include <list>
using namespace std;

// Used to track farthest node.
int x;

// Sets maxCount as maximum distance from node.
void dfsUtil(int node, int count, bool visited[],
				int& maxCount, list<int>* adj)
{
	visited[node] = true;
	count++;
	for (list<int>::iterator i = adj[node].begin(); i != adj[node].end(); ++i) {
		if (!visited[*i]) {
			if (count >= maxCount) {
				maxCount = count;
				x = *i;
			}
			dfsUtil(*i, count, visited, maxCount, adj);
		}
	}
}

// The function to do DFS traversal. It uses recursive
// dfsUtil()
void dfs(int node, int n, list<int>* adj, int& maxCount)
{
	bool visited[n + 1];
	int count = 0;

	for (int i = 1; i <= n; ++i)
		visited[i] = false;

	dfsUtil(node, count + 1, visited, maxCount, adj);
}


int diameter(list<int>* adj, int n)
{
	int maxCount = INT_MIN;

	dfs(1, n, adj, maxCount);
	dfs(x, n, adj, maxCount);

	return maxCount;
}

/* Driver program to test above functions*/
int main()
{
  int t; cin>>t;
  while(t--)
  {
    int n; cin>>n;
    list<int> adj[n+1];
    for(int i=0; i<n-1;i++)
    {
      int a , b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    x = 0;
    if(n==1) std::cout << 1 << '\n';
    else std::cout << diameter(adj, n) << '\n';



  }
		return 0;
}
