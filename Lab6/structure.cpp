#include <iostream>
using namespace std;
#include<algorithm>

struct item
{
    int w;
    int p;
    float r = p / (float)w;
} it[10];

bool compare(item i1, item i2)
{
    if (i1.r < i2.r)
    {
        return true;
    }
    return false;
}

int main()
{
    int W, no_it;
    cout << "Enter weight of knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> no_it;

    for (int i = 0; i < no_it; i++)
    {
        cout << "Enter profit and value: ";
        cin >> it[i].w;
        cin >> it[i].p;
    }

    sort(it, it + no_it, compare);

    for (int i = 0; i < 5; i++)
    {
        cout << it[i].w << "\t\t" << it[i].p << "\t\t" << it[i].r << endl;
    }

    return 0;
}