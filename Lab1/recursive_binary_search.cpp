#include <iostream>
using namespace std;

int binary_search (int arr[], int lb, int ub, int key)
{
    int mp;

    if (lb == ub)
    {
        if (arr[lb] == key)
        {
            return lb;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        mp = (lb + ub) / 2;
        if (key == arr[mp])
        {
            return mp;
        }
        else if (key < arr[mp])
        {
            binary_search(arr, lb, mp - 1, key);
        }
        else
        {
            binary_search(arr, mp + 1, ub, key);
        }
    }
}

int main()
{
    int arr[50];
    int n, key, res;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number to be searched: ";
    cin >> key;

    int lb = 0, ub = n - 1;

    res = binary_search(arr, lb, ub, key);
    if(res != -1)
    {
        cout << key << " is present at index: "<< res + 1;
    }
    else
    {
        cout << key << " is not present";
    }

    return 0;
}
