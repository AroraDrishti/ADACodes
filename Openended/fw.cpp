#include <iostream>
using namespace std;
#define V 4
#define INF INT_MAX

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
  
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) 
    {
        for (i = 0; i < V; i++) 
        {
            for (j = 0; j < V; j++) 
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                else if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }   
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if(dist[i][i] < 0)
        {
            cout << "Negative edge weight cycle is present" << endl;
            return;
        }
    }
    
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            if(dist[i][j] > 100)
            {
                cout << "INF\t\t";
            }
            else
            {
                cout << dist[i][j] << "\t\t";
            }           
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V];

    cout << "Enter adjacency matrix" << endl;
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 99)
            {
                graph[i][j] = INF;
            }
        }
    }
 
    floydWarshall(graph);
    return 0;
}