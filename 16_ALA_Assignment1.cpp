#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;
#define ll long long
int const N = 4;
void echelonForm()
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
        for (ll j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return;
}

int determinant(int A[N][N], int n)
{
    int D = 0; 
    if (n == 1)
        return A[0][0];
 
    int temp[N][N]; 
 
    int sign = 1;
 
    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
 
    return D;
}

void adjoint(int A[N][N], int adj[N][N])
{
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[N][N];
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            getCofactor(A, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}

void display(int A[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

bool inverse(int A[N][N], float inverse[N][N])
{

    int det = determinant(A, N);
    if (det == 0) 
        return false;
 

    int adj[N][N];
    adjoint(A, adj);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inverse[i][j] = adj[i][j] / float(det);
    display(A);
    return true;
}

void matmul(int r1, int c1, int arr[][3], int r2, int c2, int arr1[][2])
{
    int c[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j]=0;
            for (int k = 0; k < r2; k++)
            {
                c[i][j] += arr[i][k] * arr1[k][j];
            }
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void norm(int arr[][])
{
    int row = 2, col = 2;
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += (arr[i][j] * arr[i][j]);
        }
    }
    double norm1;
    norm1 = sqrt(sum);
    cout << norm1 << endl;
    return;
}

void rankOfMatrix()
{
    int arr[8][8], i, j, n, k, m, r, N, z, R, p, q, v;
	// cin >> n >> m;
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
	z = 0;
	for (i = 0; i < n; i++)
	{
		int c = 0;
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				c++;
			}
		}
		if (c == m)
		{
			z++;
		}
	}
	R = n - z;
	cout << "Rank = " << R << endl;
    return;
}

void sysOfEquation()
{
    int n, i, j, k;
    cout.precision(4); 
    cout.setf(ios::fixed);
    cout << "\nEnter the no. of equations\n";
    cin >> n;                
    float a[n][n + 1], x[n]; 
    cout << "\nEnter the elements of the augmented-matrix row-wise:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            cin >> a[i][j]; 
    for (i = 0; i < n; i++) 
        for (k = i + 1; k < n; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
                for (j = 0; j <= n; j++)
                {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
    for (i = 0; i < n - 1; i++) 
        for (k = i + 1; k < n; k++)
        {
            double t = a[k][i] / a[i][i];
            for (j = 0; j <= n; j++)
                a[k][j] = a[k][j] - t * a[i][j];
        }
    for (i = n - 1; i >= 0; i--) 
    {                            
        x[i] = a[i][n];          
        for (j = i + 1; j < n; j++)
            if (j != i) 
                x[i] = x[i] - a[i][j] * x[j];
        x[i] = x[i] / a[i][i]; 
    }
    cout << "\nThe values of the variables are as follows:\n";
    for (i = 0; i < n; i++)
        cout << x[i] << endl; 
    return;
}

int main()
{
    cout << "From the below given table, choose the index of the operation you wish to perform" << endl;
    cout << "0. Echleon Form; " << endl;
    cout << "1. Inverse of Matrix; " << endl;
    cout << "2. Multiplication of Matrix; " << endl;
    cout << "3. Norm of Matrix; " << endl;
    cout << "4. Rank of Matrix; " << endl;
    cout << "5. Solve linear equation; " << endl;
    int x;
    cin >> x;
    if(x == 0)
    {
        cout << "First enter the dimensions of matrix i.e. n x m, then the whole matrix " << endl;
        echelonForm();
    }
    else if(x == 1)
    {
        cout << "Enter a 4x4 matrix: " << endl;
        int A[4][4], adj[4][4];
        float inv[4][4];
        for(int i = 0;i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
                cin >> A[i][j];
        }

        adjoint(A, adj);
        if(inverse(A, inv) == false)
            cout << "Invalid Matrix" << endl;

    }
    else if(x == 2)
    {
        int arr1[2][3], arr2[3][2];
        cout << "Enter a 2x3 matrix: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> arr1[i][j];
        }
        cout << "Enter a 3x2 matrix: " << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
                cin >> arr2[i][j];
        }
        matmul(2, 3, arr1, 3, 2, arr2);

    }
    else if(x == 3)
    {
        int arr[2][2];
        cout << "Enter a 2x2 matrix" << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                cin >> arr[i][j];
        }
        norm(arr);
    }
    else if(x == 4)
    {
        cout << "Enter a 8x8 matrix: " << endl;
        rankOfMatrix();
    }
    else if(x == 5)
    {
        sysOfEquation();
    }


    return 0;
}
