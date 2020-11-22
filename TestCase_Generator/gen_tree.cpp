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
#include <random>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

ofstream outfile;

// Print to output file as 'outfile >> '

void random_tree(int n, int seed)
{
    cout << n << "\n";

    srand(seed);

    for(int i = 2; i <= n; i++)
    {
        cout << (rand() % (i - 1) + 1) << " " << i << "\n";
    }
}

void straight_chain_shuffled(int n, int seed)
{
    cout << n << "\n";

    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    shuffle(all(a), default_random_engine(seed)); ;

    for(int i = 1; i < n; i++)
    {
        cout << a[i] << " " << a[i - 1] << "\n";
    }
}


void straight_chain(int n, int seed)
{
    cout << n << "\n";

    for(int i = 2; i <= n; i++)
    {
        cout << i << " " << i - 1 << "\n";
    }
}

void wheel(int n, int seed)
{
    cout << n << "\n";

    srand(seed);

    int root = rand() % n + 1;

    for(int i = 1; i <= n; i++)
    {
        if(i == root)
        {
            continue;
        }

        cout << root << " " << i << "\n";
    }
}

void generate_testcases()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //outfile.open("out.txt");
    generate_testcases();
    //outfile.close();

    return 0;
}



