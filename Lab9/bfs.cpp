// create a queue Q
// mark v as visited and put v into Q
// while Q is non-empty
//     remove the head u of Q
//     mark and enqueue all (unvisited) neighbours of u

#include <iostream>
using namespace std;

int cost[10][10], i, j, queue[10], front, rear, visit[10], visited[10];

int main()
{
    int vert, edge;
    cout << "Enter number of vertices: ";
    cin >> vert;
    cout << "Enter number of edges: ";
    cin >> edge;

    cout << "Edges: ";
    for (int k = 1; k <= edge; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "BFS Order: " << source << " ";
    visited[source] = 1;
    
    int k = 1;

    while (k < vert)
    {
        for (int j = 1; j <= vert; j++)
            if (cost[source][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                queue[rear++] = j;
            }
        source = queue[front++];
        cout << source << " ";
        k++;
        visit[source] = 0;
        visited[source] = 1;
    }
    return 0;
}