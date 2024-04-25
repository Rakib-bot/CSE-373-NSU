#include <bits/stdc++.h>
using namespace std;
struct node
{
    int cnt = 0;
    int dir = 0;
};
int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    char a[n1 + 1];
    char b[n2 + 1];

    for (int i = 1; i <= n1; i++)
    {
        a[i] = s1[i - 1];
    }
    for (int i = 1; i <= n2; i++)
    {
        b[i] = s2[i - 1];
    }
    node dp[n1 + 1][n2 + 1];
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j].cnt = dp[i - 1][j - 1].cnt + 1;
                dp[i][j].dir = 45;
            }
            else
            {
                dp[i][j].cnt = max(dp[i][j - 1].cnt, dp[i - 1][j].cnt);
                if (dp[i][j - 1].cnt >= dp[i - 1][j].cnt)
                    dp[i][j].dir = 0;
                else
                    dp[i][j].dir = 90;
            }
        }
    }
    cout << dp[n1][n2].cnt << endl;
    int i = n1, j = n2;
    deque<char> ans;
    // for (int i = 1; i <= n1; i++)
    // {
    //     for (int j = 1; j <= n2; j++)
    //     {
    //         if (dp[i][j].dir == 45)
    //         {
    //             cout << i << " " << j << " " << dp[i][j].cnt << " " << dp[i][j].dir << " " << a[i] << endl;
    //         }
    //     }
    // }
    // cout<<dp[6][4].dir<<endl;
    // cout<<dp[5][3].dir<<endl;
    // cout<<dp[3][2].dir<<endl;
    // cout<<dp[2][1].dir<<endl;
    while (i >= 1 && (j >= 1 && j <= n2))
    {
        if (dp[i][j].dir == 45)
        {
           // cout<<i<<" "<<j<<endl;
            ans.push_front(a[i]);
            i--;
            j--;
        }
        else if (dp[i][j].dir == 0)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    for (auto x : ans)
    {
        cout << x;
    }
}