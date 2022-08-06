#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int water = 0;

        while (i < j)
        {
            water = max(water, (j-i)*(min(height[i], height[j])));

            if( height[i] < height[j] ) i++; //remove the lesser of the heights from further consideration
            else j--;
        }
        return water;
    }
};

int32_t main() {
    return 0;
}
 