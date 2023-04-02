#include <iostream>
using namespace std;

const int vert = 5;
void print_MST(int parent[], int cost[vert][vert]);
void find_MST(int cost[vert][vert]);
int min_key(int key[], bool visited[]);

int main()
{
    int cost[vert][vert];
    cout << "Enter the vertices for a graph (5 vertices):";
    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            cin >> cost[i][j];
        }
    }
    find_MST(cost);

    return 0;
}

int min_key(int key[], bool visited[])
{
    int min = 999, min_index;

    for (int v = 0; v < vert; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void print_MST(int parent[], int cost[vert][vert])
{
    int minCost = 0;
    cout << "Edge \t Weight\n";
    for (int i = 1; i < vert; i++)
    {
        cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
        minCost += cost[i][parent[i]];
    }
    cout << "Total cost is " << minCost;
}

void find_MST(int cost[vert][vert])
{
    int parent[vert], key[vert];
    bool visited[vert];

    for (int i = 0; i < vert; i++)
    {
        key[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < vert - 1; x++)
    {
        int u = min_key(key, visited);
        visited[u] = true;

        for (int v = 0; v < vert; v++)
        {
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    print_MST(parent, cost);
}