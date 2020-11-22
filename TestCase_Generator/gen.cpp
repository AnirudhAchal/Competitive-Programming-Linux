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

void print_cube(vector<vector<ll>> cube)
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << cube[i][j] << " ";
        }
        cout << "\n";
    }
}

void generate_testcases()
{
    /*vector<vector<ll>> cube = {
        {1, 2, 12313},
        {1, 4, 13521},
        {1, 5, 13222},
        {4, 6, 10012},
        {4, 3, 15400},
        {7, 6, 15640},
        {7, 3, 11330},
        {7, 8, 16640},
        {8, 5, 13006},
        {8, 2, 19864},
        {5, 6, 12345},
        {3, 2, 12423}
    };*/
    /*vector<vector<ll>> cube = {
        {1, 2, 10},
        {1, 4, 12},
        {1, 5, 132},
        {4, 6, 121},
        {4, 3, 132},
        {7, 6, 124},
        {7, 3, 143},
        {7, 8, 175},
        {8, 5, 11},
        {8, 2, 13},
        {5, 6, 156},
        {3, 2, 12}
    };*/
    vector<vector<ll>> cube = {
        {1, 8, 2321},
        {8, 7, 14252},
        {3, 1, 1342},
        {3, 7, 631},
        {3, 6, 125},
        {5, 1, 74451},
        {8, 2, 1363},
        {4, 7, 1745},
        {2, 5, 172},
        {2, 4, 174},
        {4, 6, 1254},
        {6, 5, 361}
    };



    print_cube(cube);

    int Q = 2000;
    cout << Q << "\n";

    for(int i = 0; i < Q; i++)
    {
        cout << i << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //outfile.open("input01.txt");
    generate_testcases();
    //outfile.close();


    return 0;
}

