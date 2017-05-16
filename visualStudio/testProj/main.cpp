// http://www.spoj.com/problems/PPATH/
// PPATH - Prime Path
// BFS - Find the shotest path
// Going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime. 


#if 1

#include <iostream>
#include <vector>
// Find the all possible prime numbers
#include <bitset>
#define SIZE 10000000
#define MAX (int)(SIZE-3)/2
using namespace std;
 
int primes[MAX+1];                                     //array that stores the primes up to sqrt(SIZE)
bitset<MAX+1> bset;                                    //auxiliary bitset used to make the sieve
 
void Sieve_GeneratePrimes()
{
	int i,j;
	for(i=0;i*i<=SIZE;i++)                             //we only have to get primes up to sqrt(SIZE)
		if(!bset.test(i))
			 for(j=i+1;(2*j+1)*(2*i+3)<=SIZE;j++)
				  bset.set(((2*j+1)*(2*i+3)-3)/2);     //setting all non-primes
	primes[0]=2;                                       //store the first prime (that is 2)
	for(i=1,j=0;j<MAX+1;j++)
	   if(!bset.test(j))
		  primes[i++]=2*j+3;                           //store the remaining odd primes    
}
 
bool isSingleDigitDiff(unsigned int a, unsigned int b)
{
	unsigned int diff = 0; 

	while(1)
	{
		if(a % 10 != b % 10) diff++;
		a /= 10;
		b /= 10;
		if(!a || !b || diff > 1)
		{
			if(diff == 1) return true;
			else return false;
		}			
	}
}

int main() {
	Sieve_GeneratePrimes();
	// for(int i=0; i<100; ++i)                           // Upper limit can be up to 10000000
	//	cout<< primes[i] << " ";

	vector<int> fourDigits;	
	unsigned int i = 0;
	while(1)
	{
		if(primes[i] > 999 && primes[i] < 10000) fourDigits.push_back(primes[i]);
		if(primes[i] > 10000) break;
		++i;
	}

	unsigned int a = 0;
	vector<int> oneDigitDiff;	
	a = 1033;
	for(unsigned int i = 0;  i < fourDigits.size(); ++i)
	{
		if(isSingleDigitDiff(a, fourDigits[i])) oneDigitDiff.push_back(fourDigits[i]);
	}

	return 0;
}



#elif 0
#include <iostream>
#include <vector>

#include <bitset>
#define SIZE 10000000
#define MAX (int)(SIZE-3)/2
using namespace std;
 
int primes[MAX+1];                                     //array that stores the primes up to sqrt(SIZE)
bitset<MAX+1> bset;                                    //auxiliary bitset used to make the sieve
 
void Sieve_GeneratePrimes()
{
	int i,j;
	for(i=0;i*i<=SIZE;i++)                             //we only have to get primes up to sqrt(SIZE)
		if(!bset.test(i))
			 for(j=i+1;(2*j+1)*(2*i+3)<=SIZE;j++)
				  bset.set(((2*j+1)*(2*i+3)-3)/2);     //setting all non-primes
	primes[0]=2;                                       //store the first prime (that is 2)
	for(i=1,j=0;j<MAX+1;j++)
	   if(!bset.test(j))
		  primes[i++]=2*j+3;                           //store the remaining odd primes    
}
 
int main() {
	Sieve_GeneratePrimes();
	for(int i=0; i<100; ++i)                           // Upper limit can be up to 10000000
		cout<< primes[i] << " ";

	vector<int> fourDigits;
	unsigned int c = 0;
	unsigned int i = 0;
	while(1)
	{
		if(primes[i] > 999 && primes[i] < 10000) fourDigits.push_back(primes[i]);
		if(primes[i] > 10000) break;
		++i;
	}

	return 0;
}

#elif 0
#include <iostream>
#include <list> 
using namespace std;
// Check 1 digit difference of 1234: (Imagine one new digit placed on top of it)
// 1254, 3234 etc.

bool isSingleDigitDiff(unsigned int a, unsigned int b)
{
	unsigned int diff = 0; 

	while(1)
	{
		if(a % 10 != b % 10) diff++;
		a /= 10;
		b /= 10;
		if(!a || !b || diff > 1)
		{
			if(diff == 1) return true;
			else return false;
		}			
	}
}

int main()
{
	bool result; 
	result = isSingleDigitDiff(1234,1254);
	result = isSingleDigitDiff(1234,1256);
	return 0;
}

#elif 0
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
    g.BFS(0);
 
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