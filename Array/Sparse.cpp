#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int arr[n * (n + 1) / 2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int index = (i * (i + 1)) / 2 + j;
            arr[index] = mat[i][j];
        }
    }
    // access A[3][2] (1-based → convert to 0-based)
    int i = 3-1;
    int j = 2-1;

    if (i >= j)
    {
        int index = (i * (i + 1)) / 2 + j;
        cout << arr[index] << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}