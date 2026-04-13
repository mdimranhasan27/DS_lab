#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int mat[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    int arr1[r * c];
    int arr2[r * c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr1[(j * r) + i] = mat[i][j]; // column major order
            arr2[(i * c) + j] = mat[i][j]; // row major order .
        }
    }
    // Row-Major Order Formula: index = (row * width) + column
    // Column-Major Order Formula: index = (column * height) + row
    for (int i = 0; i < r * c; i++)
    {
        cout << "arr1[" << i << "] = " << arr1[i] << endl;
    }

    for (int i = 0; i < r * c; i++)
    {
        cout << "arr2[" << i << "] = " << arr2[i] << endl;
    }

    cout << "Print row 3 : \n";
    int row = 2; // 3rd row

    for (int j = 0; j < c; j++)
    {
        cout << arr2[row * c + j] << " ";
    }
    cout << "\n Print column 2 : \n";
    int col=1 ; // 2ndd row

    for (int i = 0; i < r; i++)
    {
        cout << arr1[col*r+ i] << " ";
    }

    return 0;
}