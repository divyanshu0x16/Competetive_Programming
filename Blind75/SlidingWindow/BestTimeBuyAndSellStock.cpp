#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
        int buy = 0;

        int minPrice = 10001;
        int maxProfit =  0;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};

int32_t main() {
    vector<int> prices = {2, 4, 1};
    Solution s;
    cout << s.maxProfit(prices) << "\n";
    return 0;
}
 