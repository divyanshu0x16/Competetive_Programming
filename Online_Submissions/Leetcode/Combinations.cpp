#include <iostream>
#include <vector>
#include <string>

//Combinations : https://leetcode.com/problems/combinations

/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
*/

using namespace std;

string toString(vector<int> v) {
    string ans = "[";
    for (int i: v) {
        ans += i + '0';
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2) + "]";
    return ans;
}

string toString(vector<vector<int>> v) {
    string ans = "[";
    for (vector<int> i: v) {
        ans += toString(i);
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2) + "]";
    return ans;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c(k, 0); // vector of length k, all 0s
        int i = 0;
        while (i >= 0) {
            // Increment element at index i
            c[i]++;
            cout << "Incremented element at index " << i << endl;
            cout << toString(c) << endl;
            
            /* Move index to the left if the element
             * at index i has exceeded n.
             */
            if (c[i] > n) {
                i--;
                cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
            }
            
            /* If the index is at the end of the vector
             * c, then (because the other conditions are
             * obeyed), we know we have a valid combination,
             * so push it to our ans vector<vector<>>
             */
            else if (i == k - 1) {
                ans.push_back(c);
                cout << "Combination found!" << endl;
                cout << "Added " << toString(c) << " as an answer!" << endl;
            }
            
            /* Move index to the right and set the
             * element at that index equal to the
             * element at the previous index.
             * 
             * Because of the increment at the beginning
             * of this while loop, we ensure that the
             * element at this index will be at least
             * one more than its neighbor to the left.
             */
            else {
                i++;
                c[i] = c[i - 1];
                cout << "Moved index to the right, and copied the value"
                << " from the left" << endl;
                cout << toString(c) << endl;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << toString(sol.combine(4, 3)) << endl;
    return 0;
}