#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &v, int n, int i)
{
    // this function is used to maintain the heap property and it works until the root node is greater than its child node

    int largest = i;
    int left = 2 * i + 1; // 0 based index
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
    {
        largest = left;
    }
    if (right < n && v[right] > v[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
        // we call it beacuse we have to check the heap property for the child node also
    }
}
void build_Max_Heap(vector<int> &v, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // we start from n/2-1 because the last node is at n-1 index and its parent is at (n-1)/2 index.we don't need to check the leaf node because it is already a heap
        heapify(v, n, i);
    }
}
void heapSort(vector<int> &v, int n)
{
    build_Max_Heap(v, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
int main()
{
    vector<int> v = {11, 11, 13, 5, 6, 7, -1};
    heapSort(v, v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}