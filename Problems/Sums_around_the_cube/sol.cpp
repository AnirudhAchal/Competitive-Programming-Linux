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

vector<pair<int, ll>> adj[9];

void solve()
{
    for(int i = 1; i <= 12; i++)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    int Q;
    cin >> Q;

    while(Q--)
    {
        int T;
        cin >> T;

        vector<ll> dp(9, 0);
        vector<ll> path_count(9, 0);

        path_count[1] = 1;

        for(int i = 1; i <= T; i++)
        {
            // Update Path Counts
            vector<ll> path_count_temp = path_count;
            for(int v = 1; v <= 8; v++)
            {
                path_count[v] = 0;
                for(pair<int, ll> x : adj[v])
                {
                    path_count[v] += path_count_temp[x.first];
                    path_count[v] %= MOD;
                }
            }

            // Update Sums
            vector<ll> dp_temp = dp;
            for(int v = 1; v <= 8; v++)
            {
                dp[v] = 0;
                for(pair<int, ll> p : adj[v])
                {
                    dp[v] += dp_temp[p.first];
                    dp[v] %= MOD;

                    dp[v] += p.second * path_count_temp[p.first];
                    dp[v] %= MOD;
                }
            }
        }

        cout << dp[1] << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}





