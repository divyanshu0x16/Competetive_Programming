#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:

    static bool sortcol(const vector<int>& v1, const vector<int>& v2){
        if( v1[0] == v2[0] ) {
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //First we sort based on width
        sort(envelopes.begin(), envelopes.end(), sortcol);
        //Then we LIS on Russian Doll Envelopes
        int n = envelopes.size();

        //LIS in O(nlogn)
        //dp[i] is element at which subsequence of length i terminates
        //If there are multiple such elements, take the one that ends in the smallest element


        /*
        IMPORTANT OBSERVATION:
        The array d will always be sorted: d[i-1] <= d[i] for all 1 to n. 
        And also the element a[i] will only update at most one value d[j].

        Thus we can use binary search to find this elment in O(logn),
        */
        const int INF = 1e9;
        vector<int> dp(n, INF);

        dp[0] = -INF;

        for (int i = 0; i < n; i++)
        {
            int j = upper_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            if( dp[j-1] < envelopes[i][1] and envelopes[i][1] < dp[j] )
                dp[j] = envelopes[i][1];
        }
        
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if(dp[i] < INF)
                ans = i;
        }
        return ans;
    }
};



int32_t main() {
    Solution s;
    vector<vector<int>> enve = {{5,4},{6,4},{6,7},{2,3}};
    cout << s.maxEnvelopes(enve) << '\n';
    return 0;
}
 