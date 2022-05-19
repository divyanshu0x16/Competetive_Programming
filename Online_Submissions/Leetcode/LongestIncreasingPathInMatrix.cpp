#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

/*
1. Do DFS on every cell
2. Compare every 4 direction and skip cells that are out of boundary
3. Get matrix maximum from every cell's maximum
4. User matrix[x][y] <= matrix[i][j] so we don't need a visited[m][n] array
5. We cache the distance because it's possible to revisit a cell

*/

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache (m, vector<int> (n, 0));
        int maximum  = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int len = dfs(matrix, i, j, m, n, cache);
                maximum = max(maximum, len);
            }
            
        }
        return maximum;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& cache){
        if(cache[i][j] != 0) return cache[i][j]; //The path has already been calculated
        int maximum = 1;
        for(auto dir: dirs){
            int x = i + dir[0], y = j + dir[1];
            if( x < 0 or x >= m or y < 0 or y >= n or matrix[x][y] <= matrix[i][i] ) continue;
            int len = 1 + dfs(matrix, x, y, m, n, cache);
            maximum = max(maximum, len);
        }
        cache[i][j] = maximum;
        return maximum;
    }
};

int32_t main() {
    Solution s;
    vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout << s.longestIncreasingPath(matrix) << "\n";
    return 0;
}
 