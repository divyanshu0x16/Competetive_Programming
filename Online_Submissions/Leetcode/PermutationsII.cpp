#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {

private:
    void recursion(vector<int> nums, int i, int j, vector<vector<int> > &res){
        if(i == j - 1){ //Means we are at the end
            res.push_back(nums);
            return;
        }
        for(int k = i; k < j; k++){
            if(i != k and nums[i] == nums[k]) continue; //Duplicate number, but different orig index
            swap(nums[i], nums[k]);
            recursion(nums, i+1, j, res);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        recursion(nums, 0, nums.size(), res);
        return res;
    }
};

int32_t main() {
    return 0;
}
 