/*COMPETITIVE PROGRAMMING C++ TEMPLATE */

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
#include <fstream>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

const int maxN = 1e5;
vector<int> adj[maxN + 1];
vector<bool> vis(maxN + 1, false);

void dfs(int v)
{
    vis[v] = true;

    for(int x : adj[v])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
}

void reset(int n)
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = false;
        adj[i].clear();
    }
}

void solve()
{
    int n;
    cin >> n;

    reset(n);

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cout << "Not a Tree!\n";
            exit(0);
        }
    }

    cout << "Valid Tree\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}



