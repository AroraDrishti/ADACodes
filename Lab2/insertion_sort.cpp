#include <iostream>
using namespace std;

void insertion_sort (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = current;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main()
{
    int n, arr[50];
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements in the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertion_sort (arr, n);
    return 0;
}