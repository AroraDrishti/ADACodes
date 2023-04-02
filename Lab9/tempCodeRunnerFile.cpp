#include <iostream>
using namespace std;

int cost[10][10], i, j, k, n, stk[10], top, visit[10], visited[10];
int main()
{
    int vert, edge;
    cout << "Enter no of vertices:";
    cin >> vert;
    cout << "Enter no of edges:";
    cin >> edge;

    cout << "Edges: ";
    for (int k = 1; k <= edge; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
    }

    int source, k = 1;
    cout << "Enter source vertex: ";
    cin >> source;

    cout << "DFS Order: ";
    cout << source << " ";
    visited[source] = 1;

    while (k < vert)
    {
        for (int j = vert; j >= 1; j--)
            if (cost[source][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                stk[top] = j;
                top++;
            }
        source = stk[--top];
        cout << source << " ";
        k++;
        visit[source] = 0;
        visited[source] = 1;
    }
    return 0;
}