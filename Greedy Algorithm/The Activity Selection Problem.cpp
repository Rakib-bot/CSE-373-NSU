
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
    for(auto i:v)
    {
         cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    int count = 1;
    // int st = v[0].first;
    vector<pair<int,int>>task;
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
    for(auto i:task)
    {
         cout<<i.first<<" "<<i.second<<endl;
    }

}