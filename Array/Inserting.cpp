#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    vector<int> v(size + 5);
    vector<string> p(size + 5);

    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> p[i];
    }
    //one
    int target;
    cin >> target;
    for (int i = size - 1; i >= 0; i--)
    {
        if (v[i] < target)
        {
            v[i + 1] = target;
            break;
        }
        else
            v[i + 1] = v[i];
    }
    for (int i = 0; i < size + 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    //two
    string tgt;
    cin >> tgt;
    for (int j = size - 1; j >= 0; j--)
    {
        if (p[j] < tgt)
        {
            p[j + 1] = tgt;
            break;
        }
        else
            p[j + 1] = p[j];
    }
    for (int j = 0; j < size + 1; j++)
    {
        cout << p[j] << " ";
    }
    cout << "\n";
    //three
    int val, pos;
    cin >> val >> pos;
    for (int k = size; k >= pos - 1; k--)
    {
        v[k + 1] = v[k];
    }
    v[pos - 1] = val;
    for (int i = 0; i < size + 2; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    //four
    string value;
    int position;
    cin >> value >> position;
    for (int k = size; k >= position - 1; k--)
    {
        p[k + 1] = p[k];
    }
    p[position - 1] = value;
    for (int i = 0; i < size + 2; i++)
    {
        cout << p[i] << " ";
    }
}