#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
#define int long long
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define modulo(a, b) (a % b < 0 ? a % b + b : a % b)
#define intpow(a, b) (int)(pow(a, b) + 0.5)
#define gcd(a, b) __gcd(a, b)
#define all(x) (x).begin(), (x).end()
#define ps(x, y) fixed << setprecision(y) << x
#define testcase(x) \
    int x;          \
    cin >> x;       \
    while (x--)
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

class Solution
{
public:
    int nearestExit(vector<vector<char> > &maze, vector<int> &entrance)
    {
        int n = maze.size();    //Rows
        int m = maze[0].size(); //Columns

        vector<vector<bool>> visited(n, vector<bool> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == '.')
                    visited[i][j] = false;
                else
                    visited[i][j] = true;
            }
        }

        queue<pair<pair<int, int>, int>> q;
        visited[entrance[0]][entrance[1]] = true;
        q.push(make_pair(make_pair(entrance[0], entrance[1]), 1));
        while (!q.empty())
        {
            pair<int, int> curr = q.front().first;
            int currDist = q.front().second;
            int currX = curr.first;
            int currY = curr.second;
            q.pop();

            if (currX == 0 or currX == n - 1 or currY == 0 or currY == m - 1)
                if (make_pair(currX, currY) != make_pair(entrance[0], entrance[1]))
                    return currDist;

            //Moving Up
            if (currX - 1 >= 0 and visited[currX - 1][currY] == false)
            {
                q.push(make_pair(make_pair(currX - 1, currY), currDist + 1));
                visited[currX-1][currY] = true;
            }

            //Moving Down
            if (currX + 1 < n and visited[currX + 1][currY] == false)
            {
                q.push(make_pair(make_pair(currX + 1, currY), currDist + 1));
                visited[currX + 1][currY] = true;
            }

            //Moving Left
            if (currY - 1 >= 0 and visited[currX][currY - 1] == false)
            {
                q.push(make_pair(make_pair(currX, currY - 1), currDist + 1));
                visited[currX][currY - 1] = true;
            }

            //Moving Right
            if (currY + 1 < m and visited[currX][currY + 1] == false)
            {
                q.push(make_pair(make_pair(currX, currY + 1), currDist + 1));
                visited[currX][currY + 1] = true;
            }
        }
        return -1;
    }
};

int32_t main()
{
    fastIO;
    int t = 1;
    while (t--)
    {
        Solution s;
        vector<vector<char> > maze { {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
        vector<int> entrance{1,0};
        cout << s.nearestExit(maze, entrance) << "\n";
    }
    return 0;
}
