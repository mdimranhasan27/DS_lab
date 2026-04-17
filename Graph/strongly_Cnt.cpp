#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    cin >> v;
    vector<vector<int>> Path(v, vector<int>(v));
    vector<vector<int>> Path1(v, vector<int>(v));
    vector<vector<int>> B(v, vector<int>(v, 0));
    cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> Path[i][j];
            Path1[i][j] = Path[i][j];
        }
    }
    for (int b = 0; b < v; b++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                for (int k = 0; k < v; k++)
                {
                    Path[i][j] += Path[i][k] * Path1[k][j];
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (Path[i][j] > 0)
                B[i][j] = 1;

            sum += B[i][j];
        }
    }
    cout << "\nThe Path Matrix (Transitive Closure) is:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    if (sum == v * v)
        cout << "the graph is strongly connected\n";
    else
        cout << "not strongly connected\n";

    return 0;
}
