#include <iostream>
#include <vector>

using namespace std;

void findPathMatrix(int V, vector<vector<int>>& path) {
    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        // i is the source vertex
        for (int i = 0; i < V; i++) {
            // j is the destination vertex
            for (int j = 0; j < V; j++) {
                // If there is a path from i to k AND k to j, then there's a path from i to j
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }
}

int main() {
    int V;
    cout << "Enter the number of nodes: ";
    cin >> V;

    vector<vector<int>> path(V, vector<int>(V));
    cout << "Enter the adjacency matrix (0 or 1):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> path[i][j];
        }
    }

    findPathMatrix(V, path);

    cout << "\nThe Path Matrix (Transitive Closure) is:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
