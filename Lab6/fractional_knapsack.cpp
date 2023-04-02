#include <iostream>
using namespace std;
int main()
{
    int array[2][100], n, W, i, curweight, used[100], max = -1, totalprofit = 0;

    cout << "Enter number of objects: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    
    for (i = 0; i < n; i++)
    {
        cout << "Enter the weight " << i + 1 << ":";
        cin >> array[0][i];
        cout << "Enter the Profit " << i + 1 << ":";
        cin >> array[1][i];
    }

    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }

    curweight = W;

    while (curweight >= 0)
    {
        max = -1;
        for (i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((max == -1) || 
            (((float)array[1][i] / (float)array[0][i]) > ((float)array[1][max] / (float)array[0][max]))))
            {
                max = i;
            }
        }

        used[max] = 1;

        curweight = curweight - array[0][max];
        totalprofit = totalprofit + array[1][max];

        if (curweight >= 0)
        {
            cout << "\nAdded object " << max + 1 << " Weight: " << array[0][max] 
                 << " Profit: " << array[1][max] << " completely in the bag, Remaining weight: " << curweight;
        }
        else
        {
            cout << "\nAdded object " << max + 1 << " Weight: " << (array[0][max] + curweight) 
                 << " Profit: " << (array[1][max] / array[0][max]) * (array[0][max] + curweight) 
                 << " partially in the bag, Remaining weight: 0"
                 << " Weight added is: " << curweight + array[0][max];
            totalprofit = totalprofit - array[1][max];
            totalprofit = totalprofit + ((array[1][max] / array[0][max]) * (array[0][max] + curweight));
        }
    }
    cout << "\nTotal Profit: " << totalprofit;
    return 0;
}