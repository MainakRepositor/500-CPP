// C++ program to check if a given directed graph is strongly
// connected or not
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // An array of adjacency lists

	// A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
public:
	// Constructor and Destructor
	Graph(int V) { this->V = V; adj = new list<int>[V];}
	~Graph() { delete [] adj; }

	// Method to add an edge
	void addEdge(int v, int w);

	// The main function that returns true if the graph is strongly
	// connected, otherwise false
	bool isSC();

	// Function that returns reverse (or transpose) of this graph
	Graph getTranspose();
};

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// Function that returns reverse (or transpose) of this graph
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// The main function that returns true if graph is strongly connected
bool Graph::isSC()
{
	// St1p 1: Mark all the vertices as not visited (For first DFS)
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Step 2: Do DFS traversal starting from first vertex.
	DFSUtil(0, visited);

	// If DFS traversal doesn’t visit all vertices, then return false.
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	// Step 3: Create a reversed graph
	Graph gr = getTranspose();

	// Step 4: Mark all the vertices as not visited (For second DFS)
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Step 5: Do DFS for reversed graph starting from first vertex.
	// Staring Vertex must be same starting point of first DFS
	gr.DFSUtil(0, visited);

	// If all vertices are not visited in second DFS, then
	// return false
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

// Driver program to test above functions
int main()
{
	// Create graphs given in the above diagrams
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 0);
	g1.addEdge(2, 4);
	g1.addEdge(4, 2);
	g1.isSC()? cout << "Yes\n" : cout << "No\n";

	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.isSC()? cout << "Yes\n" : cout << "No\n";

	return 0;
}
