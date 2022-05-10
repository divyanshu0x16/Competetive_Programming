#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

*/


/*Algorithm




*/

class Solution {
    void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; //backtrack
        if(currSum==target){
            ans.push_back(currComb); //store the solution and backtrack
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
            
            currComb.push_back(candidates[i]); //put 1 option into the combination
            
            currSum+=candidates[i];
            
            combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
            
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
            
            currSum-=candidates[i];
        } 
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans);
        return ans;
    }
};

int32_t main() {
    return 0;
}
 