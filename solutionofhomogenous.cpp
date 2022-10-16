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

    int z = 0;
    for (i = 0; i < n; i++)
    {
        int c = 0;
        for (j = 0; j < n + 1; j++)
        {
            if (a[i][j] == 0)
            {
                c++;
            }
        }
        if (c == n + 1)
        {
            z++;
        }
    }
    int R = n - z;
    // cout << "Rank = " << R << endl;

    // for (float p = 0; p < n; p++)
    // {
    //     for (float q = n - 2; q < n; q++)
    //     {
    //         if (a[i][j] != 0 && a[i][j + 1] == 0)
    //         {
    //             cout << "NO SOLUTION POSSIBLE: " << endl;
    //             break;
    //         }
    //     }
    // }

    int flag = 0;

    if (R != n + 1)
    {
        for (i = 0; i < n; i++)
        {
            if (x[i] / x[i] != 1)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 3;
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (x[i] / x[i] != 1)
            {
                flag = 1;
                break;
            }
            else
            {
                flag == 2;
            }
            // cout << x[i] << endl;
        }
    }
    if (flag == 1)
    {
        cout << "NO SOLUTION POSSIBLE! " << endl;
    }
    else if (flag == 3)
    {
        cout << "INFINITE SOLUTION POSSIBLE!" << endl;
    }
    else if (flag == 2)
    {
        cout << "Following are the solutions: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << endl;
        }
    }
    return 0;
}