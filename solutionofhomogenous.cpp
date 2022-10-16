#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, i, j, k;
    cin >> n;
    float a[n][n + 1];
    float x[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (abs(a[i][i]) < abs(a[k][i]))
            {
                for (j = 0; j <= n; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            double t = a[k][i] / a[i][i];
            for (j = 0; j <= n; j++)
            {
                a[k][j] = a[k][j] - t * a[i][j];
            }
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++)
        {
            if (j != i)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }
        }
        x[i] = x[i] / a[i][i];
    }

    cout << "\nThe values of the variables are as follows:\n";
    for (i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }
    return 0;
}
