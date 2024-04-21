
// Problem: Fractional KnapScak problem
// Problem Link: https://www.hackerrank.com/contests/smart-interviews/challenges/si-fractional-knapsack/problem
// Contest: SPOJ - SPE
// Solution:
/*
  input format:
    3 => n of items
    60 10 => profit(Pi) and weight(Wi) of item  1 to n items
    100 20 => Pi Wi
    120 30
    50 => W (total weight of knapsack)
*/
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int profit;
    int weight;
    double ratio;
};
bool cmp(item a, item b)
{
    return a.ratio > b.ratio;
}
int main()
{
    int n;
    cin >> n;
    vector<item> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].profit >> v[i].weight;
        v[i].ratio = (double)v[i].profit / v[i].weight; // type casting
    }
    double W;
    cin >> W;
    sort(v.begin(), v.end(), cmp); // O(nlogn)
    double ans = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        if (v[i].weight <= W)
        {
            ans += v[i].profit; // O(1)
            W -= v[i].weight;   // O(1)
        }
        else
        {
            ans += v[i].ratio * W; // O(1)
            break;
        }
    }
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    cout << ans << endl;
}