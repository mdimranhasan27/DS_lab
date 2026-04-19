#include <bits/stdc++.h>
using namespace std;

// Matrix multiplication
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B, int v)
{
    vector<vector<int>> C(v, vector<int>(v, 0));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Print matrix
void print(vector<vector<int>> M, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << M[i][j] << " ";
        cout << "\n";
    }
}
void print2(vector<vector<int>> M, int v)
{
    cout << "\nPath length 2:\n";
    cout << "_From_    _ To_   _number_  \n";
    for (int i = 0; i < v; i++)
    {

        for (int j = 0; j < v; j++)
        {
           if(M[i][j]>0)
            cout << "V" << i << " TO " << "V" << j <<" "<< M[i][j] << "\n ";
        
        }
        cout << "\n";
    }
}

int main()
{
    int v;
    cin >> v;

    vector<vector<int>> A(v, vector<int>(v));

    // Input adjacency matrix
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> A[i][j];

    // (a) Adjacent vertices
    cout << "\nAdjacency list:\n";
   
     for (int i = 0; i < v; i++)
    {
        cout << "V" << i << ": ";
        for (int j = 0; j < v; j++)
        {
            if (A[i][j] == 1)
                cout << "V" << j << " ";
        }
        cout << "\n";
    }

    // (b), (c), (d)
    vector<vector<int>> A2 = multiply(A, A, v);
    vector<vector<int>> A3 = multiply(A2, A, v);
    vector<vector<int>> A4 = multiply(A3, A, v);

    cout << "\nPaths of length 2:\n";
    print2(A2, v);

    cout << "\nPaths of length 3:\n";
    print(A3, v);

    cout << "\nPaths of length 4:\n";
    print(A4, v);

    return 0;
}