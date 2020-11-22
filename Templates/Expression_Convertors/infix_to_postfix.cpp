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
#include <cstring>
#include <cassert>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define debug2(x, y) cout << #x << " = " << x << " " << #y << " = " << y << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

bool is_operator(char c)
{
    return c == '+' ||
           c == '-' ||
           c == '*' ||
           c == '/' ||
           c == '^' ||
           c == '(' ||
           c == ')';
}

int prec(char c) 
{ 
    if(c == '^') return 3; 
    else if(c == '*' || c == '/') return 2; 
    else if(c == '+' || c == '-') return 1; 
    else return -1; 
} 

void update(stack<char> &st, string &ans, int n)
{
    if(st.top() == '(')
    {
        return;
    }

    if(st.top() == ')')
    {
        st.pop();
        while(st.top() != '(')
        {
            ans.push_back(st.top());
            st.pop();
        }
        st.pop();
        return;
    }

    char op = st.top();
    st.pop();

    while(st.size() && prec(st.top()) >= prec(op))
    {
        ans.push_back(st.top());
        st.pop();
    }

    st.push(op);
}

string infix_to_postfix(string s)
{
    int n = s.size();
    stack<char> st;
    string ans;
    
    for(int i = 0; i < n; i++)
    {
        if(is_operator(s[i]))
        {
            st.push(s[i]);
            update(st, ans, n); 
        }
        else {
            ans.push_back(s[i]);
        }
    }

    while(st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << infix_to_postfix(s) << "\n";
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



