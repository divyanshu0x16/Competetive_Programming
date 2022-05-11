#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

//We have to count the all possible no. of ways...DP!!!!!

/*
dp[n][k] means the number of strings constructed by at most k different characters.

If k = 1, use only u
If k = 2, use only o,u
If k = 3, use only i,o,u
If k = 4, use only e,i,o,u
If k = 5, use only a,e,i,o,u
*/

/*For k=1, we go 1,2,3,4,5 because possible strings can be u, ou or oo, iou, ioo or iii so on*/

/*
For recursion formula, 

Take dp[3][5] = dp[3][4] + dp[2][5] as example:
To get all combinations with a e i o u for length 3, all you need to do is plus conbinations of a e i o u for length 2 
(Just put a before all previous combination, such as a(aa)) and e i o u for length 3 (Just replace first character in all combinations with a, such as eee -> aee).
*/

class Solution {

public:
       int countVowelStrings(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(6));
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
        return dp[n][5];
    }
};

int32_t main() {
    Solution s;
    cout << s.countVowelStrings(2) << "\n";
    return 0;
}
 