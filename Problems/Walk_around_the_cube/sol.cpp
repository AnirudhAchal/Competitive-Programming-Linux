/*COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>
#include <cstring>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

void solve()
{
    int T;
    cin >> T;

    vector<ll> dp(9, 0);

    dp[1] = 1;

    for(int i = 1; i <= T; i++)
    {
        vector<ll> dp_temp = dp;

        dp[1] = dp_temp[2] + dp_temp[4] + dp_temp[5];
        dp[2] = dp_temp[1] + dp_temp[3] + dp_temp[6];
        dp[3] = dp_temp[2] + dp_temp[4] + dp_temp[7];
        dp[4] = dp_temp[3] + dp_temp[1] + dp_temp[8];
        dp[5] = dp_temp[1] + dp_temp[8] + dp_temp[6];
        dp[6] = dp_temp[2] + dp_temp[5] + dp_temp[7];
        dp[7] = dp_temp[8] + dp_temp[3] + dp_temp[6];
        dp[8] = dp_temp[5] + dp_temp[4] + dp_temp[7];

        for(int j = 1; j <= 8; j++)
        {
            dp[j] %= MOD;
        }
    }

    cout << dp[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
