#include <iostream>
using namespace std;
#define ll long long int
int main()
{
    int arr[8][8], i, j, n, k, m, r, N, z, R, p, q, v;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (arr[0][0] == 0)
    {
        for (j = 0; j < m; j++)
        {
            int z = -1;
            for (i = 1; i < n; i++)
            {
                if (arr[i][j] != 0)
                {
                    z = i;
                    break;
                }
            }
            if (z != -1)
            {
                for (v = 0; v < m; v++)
                {
                    int t = arr[0][v];
                    arr[0][v] = arr[i][v];
                    arr[i][v] = t;
                }
                break;
            }
        }
    }
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            p = arr[k][k];
            q = arr[i][k];
            for (j = 0; j < m; j++)
            {
                arr[i][j] = p * arr[i][j] - q * arr[k][j];
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}