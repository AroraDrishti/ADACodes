#include <iostream>
using namespace std;

void MergeSort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int A[], int p, int q, int r)
{
    int inf, i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for(i = 1; i <= n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    
    for(j = 1; j <= n2; j++)
    {
        R[j] = A[q + j];
    }

    L[n1 + 1] = inf;
    R[n2 + 1] = inf;
    i = 1;
    j = 1;

    for(int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
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
    
    MergeSort (array, p, r);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}