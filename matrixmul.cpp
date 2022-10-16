#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <stdio.h>
#define n 4
void matmul(int arr[n][n], int arr1[n][n])
{
    int c[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += arr[i][k] * arr1[k][j];
            }
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[n][n];
    int arr1[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }
    matmul(arr, arr1);
}