#include <bits/stdc++.h>
using namespace std;
void insertion_Sort(vector<int> &v,int n)//void insertion_Sort(int v[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = v[i];
        for (j = i - 1; j >= 0 && v[j] > key; j--)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = key;
    }
}
int main()
{
    vector<int> v;// you can also use simple array instead of vector int v[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    insertion_Sort(v,n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
// Time Complexity: O(n^2) [Worst Case] , O(n) [Best Case]
// Space Complexity: O(1) [Worst Case] , O(1) [Best Case]
//is it stable? yes

