
#if 1
// Ref: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/

// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include <iostream>
#include <list> 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}

#else

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NMAX 10

int main()
{
	// Ref: https://www.quora.com/How-do-I-implement-BFS-on-a-graph-using-queue-in-C++
	
	//Adjacency list to store graph
	vector<int> adjlist[NMAX];

	//Arrays
	char visited[NMAX];
	int distance[NMAX];

	//Read Graph
	//First read number of vertices (N) and edges (M)
	//Then read the (undirected) edges
	//Note that vertices are zero-indexed
	int N,M;
	scanf("%d%d",&N,&M);

	for(int i=0;i<M;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	//Now do the BFS from vertex 0 to find distances to all vertices
	//Start by initialising all visited values as 0 and distances as -1
	memset(visited,0,sizeof visited);
	memset(distance,-1,sizeof distance);

	//Create the BFS queue and put the start vertex in
	distance[0]=0;
	visited[0]=1;

	queue<int> bfsq;
	bfsq.push(0);

	//BFS
	while(!bfsq.empty()) {
		int u=bfsq.front();
		bfsq.pop();

		//Now look at all neighbours of u
		// for(int v: adjlist[u])
		for(int v = adjlist[u].begin(); v != adjlist[u].end(); ++v)
		{
			//If v has not been processed yet, do that now
			if(!visited[v]) {
				visited[v]=1;
				distance[v]=distance[u]+1;
				bfsq.push(v);
			}
		}
	}

	return 0;
}

#endif