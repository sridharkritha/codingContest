Ref: https://www.quora.com/How-do-I-implement-DFS-on-a-directed-graph-using-adjacency-list-in-C++

// Adjacency list to store graph
vector<int> adjlist[NMAX];
 
// Array to mark vertices visited by DFS
char visited[NMAX];
memset(visited, 0, sizeof visited); 
 
// Read Graph
// First read number of vertices (N) and edges (M)
// Then read the directed edges
// Note that vertices are zero-indexed
int N,M;
scanf("%d%d",&N,&M);
 
for(int i=0;i<M;i++) {
  int a,b;
  scanf("%d%d",&a,&b);
  adjlist[a].push_back(b);
}
 
// DFS function 
void dfs(int u) {
  visited[u]=1;
  
  // Recurse over all children of u

      for(const int& v : adjlist[u]) {
        // If v has not been visited yet, recurse
        if(!visited[v]) dfs(v); 
      } 
    } 
     
    // Call dfs(0) and we will have the reachability to all other vertices

	
///////////////////////////////////////////////////////////////////////////////////////////////////
// 2nd solution:

#include<iostream>
#include <vector>
#include<string.h>
#include<fstream>
using namespace std;
int n, e;
vector <int> a[100];
bool b[100];
void dfs(int v)
{
	if(b[v]) return;
	b[v] = true;
	cout<<v<<" ";
	for (int i=0;i<a[v].size();i++)
		{
			dfs(a[v][i]);
		}
}

int main()
{
	cin>>n >> e ;
	for(int i = 0;i < e;i++)
	{
		int start, end;
		cin >> start >> end;
		a[start].push_back(end);
		a[end].push_back(start);
	}
	memset(b,0,sizeof(b));
	dfs(0);
	system ("pause");
	return 0;
}

