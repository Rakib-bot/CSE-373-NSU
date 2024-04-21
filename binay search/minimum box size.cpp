#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
ll w, h, n;
bool isPossible(ll x)
{
    return ((x / w) * (x / h)) >= n; // how many box can be placed in the given area
}
int main()
{
    fast();

    cin >> w >> h >> n;
    ll l = 0;
    ll r = 1;
    while (!isPossible(r))
        r *= 2; // we are finding the upper bound of the answer

    ll ans = r;
    // cout << r << nl;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (isPossible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}
