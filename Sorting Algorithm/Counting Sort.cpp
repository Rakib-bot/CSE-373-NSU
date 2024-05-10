//Counting Sort
//Time Complexity O(n)
//Space Complexity O(n)
//Linear Time for sorting
//Not Comparison based Sorting
//Invalid for  fraction or negative number
//Best for Small range number of sorting
//Not in place sorting
//Stable Sorting



#include <bits/stdc++.h>
using namespace std;
int *counting_sort(int *a, int n)//pass pointer off array
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
    }
    int freq[mx + 1];
    for (int i = 0; i <= mx; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        freq[i] += freq[i - 1];
    }
    int *output = new int[n]; // dynamically memory allocate for array  support in cpp not c
    for (int i = n - 1; i >= 0; i--)
    {
        output[freq[a[i]] - 1] = a[i]; // 0 base indexing must use  freq[a[i]]-1
        freq[a[i]]--;
    }
    return output;//return pointer of array
}
int main()
{
    int a[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int *output = counting_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}