#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bit(32, 0);

        for (int i = 0; i < candidates.size(); i++)
        {
            int x = 31;

            while (candidates[i] > 0)
            {
                if( candidates[i] & 1 ){
                    bit[x] = bit[x] + 1;
                }
                candidates[i] = candidates[i] >> 1;
                x--;
            }
        }
        return *max_element(bit.begin(), bit.end());
    }
};

int32_t main() {
    return 0;
}
 