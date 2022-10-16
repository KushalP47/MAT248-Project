#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int norm(int a[][2])
{
    int row = 2, col = 2;
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
    int row = 2, col = 2;
    int arr[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    norm(arr);
}
