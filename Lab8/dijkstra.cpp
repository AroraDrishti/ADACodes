# include <iostream>
using namespace std;

int minKey(int key[], bool vis[], int vert)
{
    int minimum = 9999, ind;
              
    for(int k = 0; k < vert; k++) 
    {
        if(vis[k] == false && key[k] <= minimum)      
        {
            minimum = key[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[10][10], int source, int vert)
{
    int key[10];                       
    bool vis[10];
     
    for(int k = 0; k < vert; k++)
    {
        key[k] = 9999;
        vis[k] = false;    
    }
    
    key[source] = 0;            
    
    for(int k = 0; k < vert; k++)                           
    {
        int m = minKey(key, vis, vert); 
        vis[m] = true;
        
        for(int k = 0; k < vert; k++)                  
        {
            if(!vis[k] && graph[m][k] && key[m]!=9999 && key[m] + graph[m][k] < key[k])
                key[k] = key[m] + graph[m][k];
        }
    }

    cout << "Vertex\tDistance from source vertex" << endl;
    
    for(int k = 0; k < vert; k++)                      
    { 
        int v = k;
        cout << v << "\t\t\t" << key[k] << endl;
    }
}

int main()
{
    int graph[10][10];
    int vert, source;

    cout << "Enter number of vertices: ";
    cin >> vert;

    cout << "Enter adjacency matrix" << endl;
    for(int i = 0; i < vert; i++)
    {
        for(int j = 0; j < vert; j++)
        {
            cin >> graph[i][j];
        }
    }
        
    cout << "Enter source vertex: ";
    cin >> source;

    DijkstraAlgo(graph, source, vert);

    return 0;                           
}