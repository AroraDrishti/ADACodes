#include <iostream>
using namespace std;

int partition(int array[], int p, int r);
void QuickSort(int array[], int p, int r);
void swap(int *a, int *b);

void QuickSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        QuickSort(array, p, q);
        QuickSort(array, q + 1, r);
    }
}

int partition(int array[], int p, int r)
{
    int x = array[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {
            i++;
            swap(array[i + 1], array[j]);
        }
    }

    swap(array[i + 1], array[r]);
    return i + 1;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, array[10];

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements in the array: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int p = 0;
    int r = n - 1;

    QuickSort(array, p, r);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}