#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        } 
    }
    return -1;
}

int main()
{
    int arr[50];
    int n, key, res;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements in array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }    

    cout << "Enter the number to be searched: ";
    cin >> key;

    res = linear_search (arr, n, key);
    if (res != -1)
    {
        cout << key << " is present at index " << res + 1;
    }
    else
    {
        cout << key << "not present";
    }

    return 0;
}