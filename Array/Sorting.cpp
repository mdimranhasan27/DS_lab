#include <bits/stdc++.h>
using namespace std;
int main()
{ // sorting integer
    vector<int> v = {1, 5, 2, 8, 4, 9, 3, 0, 12, 76, 34, 22, 56};
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    for (int x : v)
        cout << x << " ";
    cout << "\n";
    // sorting string
    vector<string> p = {"siam", "babul", "abid", "pavel", "himel", "karim", "emran", "faruk", "himel", "jony", "karim", "rony", "siam"};
    for (int i = 0; i < p.size() - 1; i++)
    {
        for (int j = 0; j < p.size() - i - 1; j++)
        {
            if (p[j] > p[j + 1])
                swap(p[j], p[j + 1]);
        }
    }
    for (string y : p)
        cout << y << " ";
    cout << "\n";
    return 0;
}