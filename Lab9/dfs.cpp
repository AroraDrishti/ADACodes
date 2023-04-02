// #include <iostream>
// using namespace std;

// int cost[10][10], i, j, k, n, stk[10], top, visit[10], visited[10];
// int main()
// {
//     int vert, edge;
//     cout << "Enter no of vertices: ";
//     cin >> vert;
//     cout << "Enter no of edges: ";
//     cin >> edge;

//     cout << "Edges: ";
//     for (int k = 1; k <= edge; k++)
//     {
//         cin >> i >> j;
//         cost[i][j] = 1;
//     }

//     int source, k = 1;
//     cout << "Enter source vertex: ";
//     cin >> source;

//     cout << "DFS Order: ";
//     cout << source << " ";
//     visited[source] = 1;

//     while (k < vert)
//     {
//         for (int j = vert; j >= 1; j--)
//             if (cost[source][j] != 0 && visited[j] != 1 && visit[j] != 1)
//             {
//                 visit[j] = 1;
//                 stk[top] = j;
//                 top++;
//             }
//         source = stk[--top];
//         cout << source << " ";
//         k++;
//         visit[source] = 0;
//         visited[source] = 1;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

int inDict(string word)
{
    string dictionary[] = {"ADA", "Machine", "Learn", "Artificial",
                           "Intelligence", "French", "Data", "analysis",
                           "i", "like", "good", "very", "subject"};

    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++)
    {
        if (dictionary[i].compare(word) == 0)  
        {
            return true;
        }    
    }   
    return false;
}

bool wordBreakDP(string str)
{
    int size = str.size();

    if (size == 0)
        return true;
    for (int i = 1; i <= size; i++)
    {
        if (inDict(str.substr(0, i)) &&
            wordBreakDP(str.substr(i, size - i)))
            return true;
    }
    return false;
}

int main()
{
    string str;
    cout << "Enter a string for the Word Break Problem:";
    cin >> str;
    wordBreakDP(str) ? cout << "Yes\n" : cout << "No\n";
    
    return 0;
}