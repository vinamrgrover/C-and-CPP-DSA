#include<iostream>
#include<list> 
#include<vector>
using namespace std; 
class graph
{
		int V; 
		vector<list<int> > adjList; 
						
public:
		graph(int v); 
		void addEdge(int src, int dest);
		void bfs(int vertex); 
}; 

graph :: graph(int v)
{
		this -> V = v; 
		adjList.resize(V);
}

void graph :: addEdge(int src, int dest)
{
		adjList[src].push_back(dest);
}

void graph :: bfs(int vertex)
{													
		list<int> queue; // for storing vertices
		vector<bool> visited(V, false); // for keeping a track of visited vertices

		visited[vertex] = true; 
		queue.push_back(vertex); 

		while(!queue.empty())
		{
				vertex = queue.front(); 
				cout << vertex << " "; 
				queue.pop_front(); 
															
				for(auto i=adjList[vertex].begin(); i!=adjList[vertex].end(); ++i)
				{
						if(!visited[*i])
						{
								visited[*i] = true; 
								queue.push_back(*i); 
						}

				}

		}

		cout << endl; 

}

int main()
{								
		graph *g = new graph(6);
		 
		g -> addEdge(0, 1);
		g -> addEdge(0, 5);
		g -> addEdge(1, 4);
		g -> addEdge(4, 3);
		g -> addEdge(3, 1);
		g -> addEdge(5, 2);

		g -> bfs(0); 

		return 0; 

}


