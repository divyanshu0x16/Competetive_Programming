#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left) + (right-left)/2;
            
            if( target == nums[mid] ) return mid;

            //Left sorted portion
            if( nums[left] <= nums[mid] )
            {
                if( target > nums[mid] or target < nums[left] )
                {
                    left = mid + 1;
                }else 
                {
                    right = mid - 1; //if target is greater than the left most value but less than middle value
                }
            }else //right sorted portion
            { 
                if( target < nums[mid] or target > nums[right])
                {
                    right = mid - 1;
                }else
                {
                    left = mid + 1; //if target is greater than mid but less than rightmost value
                }
            }
        }
        return -1;
    }
};

int32_t main() {
    return 0;
}
 