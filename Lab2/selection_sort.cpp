#include <iostream>
using namespace std;

void selection_sort (int arr[], int n)
{
    int smallest, min_index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        smallest = arr[i];
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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

    selection_sort (arr, n);
    return 0;
}