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

const int maxN = 2e5;
vector<int> adj[maxN + 1];
vector<bool> vis(maxN + 1, false);
vector<ll> children(maxN + 1);
vector<ll> sub_tree_products(maxN + 1, 1);
vector<ll> ans(maxN + 1);

void reset(int n)
{
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        children[i] = 0;
        sub_tree_products[i] = 1;
        ans[i] = 0;
    }
}

void get_children(int v)
{
    vis[v] = true;

    children[v] = 1;

    for(int x : adj[v])
    {
        if(!vis[x])
        {
            get_children(x);
            children[v] += children[x];
        }
    }
}

void get_sub_tree_products(int v)
{
    vis[v] = true;

    ll res = 1;

    for(int x : adj[v])
    {
        if(!vis[x])
        {
            get_sub_tree_products(x);

            res *= children[x];
            res %= MOD;
        }
    }

    sub_tree_products[v] = res;
}

void get_answers(int v, int root, int n)
{
    vis[v] = true;

    if(v != root)
    {
        ans[v] = sub_tree_products[v] * (n - children[v]);
        ans[v] %= MOD;
    }
    else {
        ans[v] = sub_tree_products[v];
    }

    for(int x : adj[v])
    {
        if(!vis[x])
        {
            get_answers(x, root, n);
        }
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

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    get_children(1);
    vis = vector<bool>(maxN + 1, false);

    get_sub_tree_products(1);
    vis = vector<bool>(maxN + 1, false);
    
    get_answers(1, 1, n);

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\n";
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



