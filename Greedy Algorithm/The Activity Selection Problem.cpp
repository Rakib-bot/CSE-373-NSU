// Problem: The Activity Selection Problem
// Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Note : The start time and end time of two activities may coincide.
// Input:
//  The first line of input contains N, the number of activities. There are N line input with 2 integers each, first integer denotes the start time of the activity and second integer denotes the end time of the activity.
// Output:
// print the maximum number of activities pair that can be done.

// Example:
// Input:
// 6
// 2 5
// 3 7
// 0 6
// 1 4
// 6 9
// 5 8
// Output:
// 1 4
// 5 8

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), compare);
    for (auto i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    int count = 1;
    // int st = v[0].first;
    vector<pair<int, int>> task;
    task.push_back(v[0]);
    int en = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= en)
        {
            count++;
            en = v[i].second;
            task.push_back(v[i]);
        }
    }
    for (auto i : task)
    {
        cout << i.first << " " << i.second << endl;
    }
}