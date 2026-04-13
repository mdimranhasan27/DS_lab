#include <bits/stdc++.h>
using namespace std;
int main()
{

    int size, n1, n2;
    cout << "size of one array : \n";
    cin >> n1;
    cout << "size of two array : \n";
    cin >> n2;
    size = n1 + n2;
    // for integer part
    vector<int> v(size);
    cout << "enter array one elements \n";
    for (int i = 0; i < n1; i++)
    {
        cin >> v[i];
    }
    vector<int> p(n2);
    cout << "enter array two elements \n";
    for (int i = 0; i < n2; i++)
    {
        cin >> p[i];
    }
    for (int j = 0, k = n1; k < size; k++)
    {
        v[k] = p[j];
        j++;
    }
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // for string part
    vector<string> S(size);
    cout << "enter array one elements  string\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> S[i];
    }
    vector<string> P(n2);
    cout << "enter array two elements string \n";
    for (int i = 0; i < n2; i++)
    {
        cin >> P[i];
    }
    for (int j = 0, k = n1; k < size; k++)
    {
        S[k] = P[j];
        j++;
    }
    for (string y : S)
        cout << y << " ";
    cout << "\n";

    return 0;
}