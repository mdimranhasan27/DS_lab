#include <bits/stdc++.h>
using namespace std;
int find_max(vector<int> p)
{
    int max = p[0];
    for (int j = 0; j < p.size(); j++)
    {
        if (p[j] > max)
            max = p[j];
    }
    return max;
}
int find_min(vector<int> p)
{
    int min = p[0];
    for (int k = 0; k < p.size(); k++)
    {
        if (min > p[k])
            min = p[k];
    }
    return min;
}
int average(vector<int> V)
{
    int sum = 0;
    for (int i = 0; i < V.size(); i++)
    {
        sum += V[i];
    }
    int avg = sum / V.size();
    return avg;
}
void sin_value(vector<int> v)
{
    cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        double rad = v[i] * M_PI / 180.0;
        double ans = sin(rad);
        if (abs(ans) < 1e-9)
            ans = 0;
        cout << "The sin value of " << v[i] << " is :" << ans << "\n";
    }
}
int main()
{

    printf("Enter the size of array: ");
    int size;
    cin >> size;
    vector<int> v(size);
    cout << "Enter the numbers element of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    int max_value = find_max(v);

    cout << "The maximum value is :" << max_value << "\n";

    int min_value = find_min(v);
    cout << "The minimum value is :" << min_value << "\n";
    int avg = average(v);
    cout << "The average value is : " << avg << endl;
    int total = average(v) * size;
    cout << "The Total value is : " << total << endl;
    sin_value(v);

    return 0;
}
