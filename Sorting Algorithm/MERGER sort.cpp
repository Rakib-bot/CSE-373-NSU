#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int left, int mid, int right)//call by reference (&) in c++
{
    int n1 = mid - left + 1; //calculate the size of left array from left to mid index distance+1
    int n2 = right - mid;//

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = v[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = v[mid + 1 + i];//+1 because 0 base index
    }

    leftArray.push_back(INT_MAX);//pushing infinity at the end of left array for easy  to compare
    rightArray.push_back(INT_MAX);//pushing infinity at the end of right array

    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
    {
        if (leftArray[i] <= rightArray[j])
        {
            v[k] = leftArray[i];
            i++;
        }
        else
        {
            v[k] = rightArray[j];
            j++;
        }
    }
}
void mergeSort(vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int mid = floor((left + right) / 2);

        mergeSort(v, left, mid); //left child call

        mergeSort(v, mid + 1, right);//right child call

        merge(v, left, mid, right);//parent call
        
        //this three function call is like post-order traversal of binary tree
    }
}
int main()
{
    vector<int> v = {11, 11, 13, 5, 6, 7, -1};
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}