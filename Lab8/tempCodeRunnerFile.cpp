#include <iostream>
using namespace std;

void BellmanFord(int graph[10][3], int vert, int edge, int source)
{
    int key[10];  

    for(int k = 0; k < vert; k++)
    {
        key[k] = 9999;   
    }
    key[source] = 0;

	for (int i = 0; i < vert - 1; i++) 
    {
		for (int j = 0; j < edge; j++) 
        {
			if (key[graph[j][0]] != 9999 && key[graph[j][0]] + graph[j][2] < key[graph[j][1]])
				key[graph[j][1]] = key[graph[j][0]] + graph[j][2];
		}
	}

	for (int i = 0; i < edge; i++) 
    {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (key[x] != 9999 && key[x] + weight < key[y])
			cout << "Graph contains negative weight cycle" << endl;
	}

	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < vert; i++)
    {
        cout << i << "\t\t\t" << key[i] << endl;
    }
}

int main()
{
	int vert, edge, source;
	int graph[10][3];

    cout << "Enter number of vertices: ";
    cin >> vert;

    for(int i = 0; i < vert; i++)
    {
        cout << "Enter start vertex, end vertex and weight of the edge" << vert + 1 << ": " << endl;
        for(int j = 0; j < 3; j++)
        {
            cin >> graph[i][j];
        }
    }
        
    cout << "Enter source vertex: ";
    cin >> source;
    
	BellmanFord(graph, vert, edge, source);
	return 0;
}
