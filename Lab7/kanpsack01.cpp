#include <iostream>
using namespace std;

int knapsack(int W, int w[], int v[], int n);
int max(int x, int y);

int main()
{
   int n, W;
   int v[10], w[10];

   cout << "Enter the number of items: ";
   cin >> n;
   cout << "Enter the capacity of the knapsack: ";
   cin >> W;

   for (int i = 0; i < n; i++)
   {
      cout << "Enter profit and weight for item " << i << ": ";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Profit = " << knapsack(W, w, v, n);
   return 0;
}

int knapsack(int W, int w[], int v[], int n)
{
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++)
   {
      for (wt = 0; wt <= W; wt++)
      {
         if (i == 0 || wt == 0)
         {
            K[i][wt] = 0;
         }
         else if (w[i - 1] <= wt)
         {
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         }
         else
         {   
            K[i][wt] = K[i - 1][wt];
         }
      }
   }
   return K[n][W];
}

int max(int x, int y)
{
   return (x > y) ? x : y;
}