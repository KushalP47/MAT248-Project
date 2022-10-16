#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define n 2

int norm(int a[][n])
{
    int row = n, col = n;
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += (a[i][j] * a[i][j]);
        }
    }
    double norm1;
    norm1 = sqrt(sum);
    cout << norm1 << endl;
}

int main()
{
    int row = n, col = n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    norm(arr);
}
