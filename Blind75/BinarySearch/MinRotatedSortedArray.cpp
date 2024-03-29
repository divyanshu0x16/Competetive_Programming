#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        
        if( nums[right] > nums[0] ) return nums[0];
        
        while( right >= left )
        {
            int mid = left  + (right - left)/2;
            
            if( nums[mid] > nums[mid+1] ) return nums[mid+1];
            
            if( nums[mid-1] > nums[mid] ) return nums[mid];
            
            if( nums[mid] > nums[left] ) left = mid + 1;
            else right = mid - 1;
        }
        
        return 5001;
    }
};

int32_t main() {
    return 0;
}
 