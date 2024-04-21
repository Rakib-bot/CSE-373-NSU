#include <bits/stdc++.h>
using namespace std;
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low, j = high;
    while (i < j)
    {
        while (v[i] <= pivot)
            ++i;

        while (v[j] >= pivot && j > low)
            j--;

        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}
void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int j = partition(v, low, high);
        quickSort(v, low, j);
        quickSort(v, j + 1, high);
    }
}
vector<int> randomVector(int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % 100);
    }
    return v;
}
int main()
{
    fast();
    vector<int> v;
    int n;
    cin >> n;
    v = randomVector(n);

    quickSort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
// Time Complexity: O(n^2) [Worst Case] , O(nlogn) [Best Case]
// Space Complexity: O(n) [Worst Case] , O(n) [Best Case] ,