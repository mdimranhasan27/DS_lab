#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> A(r, vector<int>(c));
    vector<vector<int>> B(r, vector<int>(c));

    // Input matrices
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> B[i][j];

    // Addition
    vector<vector<int>> add(r, vector<int>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            add[i][j] = A[i][j] + B[i][j];

    // Subtraction
    vector<vector<int>> sub(r, vector<int>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            sub[i][j] = A[i][j] - B[i][j];

    // Multiplication
    vector<vector<int>> mul(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < c; k++) {
                mul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output
    cout << "Addition:\n";
    for(auto row : add){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }

    cout << "Subtraction:\n";
    for(auto row : sub){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }

    cout << "Multiplication:\n";
    for(auto row : mul){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
}