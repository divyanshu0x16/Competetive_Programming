#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() == 0 or t.size() == 0){
            return "";
        }

        //map to keep count of all the unique characters in T
        map<char, int> dictT;
        for (int i = 0; i < t.size(); i++)
        {
            if( dictT.find(t[i]) == dictT.end() ) dictT[t[i]] = 1;
            else dictT[t[i]] += 1;
        }

        //Number of unique character in t, which need to be in the desired window
        int required = dictT.size();

        //Left and right pointer
        int l = 0, r = 0;

        //formed is used to keep track of how many unique characters in t 
        //are present in the current window in its desirec frequency
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;

        //dictionary to keep counts of all the unique characters in current window
        map<char, int> windowCounts;

        //ans list of the form (window length, left, right)
        vector<int> ans = {-1, 0, 0};

        while (r < s.size())
        {
            //Add one character from right to the window
            char c = s[r];
            if( windowCounts.find(c) == windowCounts.end()) windowCounts[c] = 1;
            else windowCounts[c] += 1;

            //if the freq of the curr character added is equal to desired count in t
            //then increment the formed count by 1
            if( windowCounts[c] == dictT[c] ) formed++;

            //Try and contract the window till the point where it ceases to be desirable
            while (l <= r and formed == required)
            {
                c = s[l];
                //Save the smallest window till now
                if( ans[0] == -1 or r-l+1 < ans[0]){
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                //The character at the poistion pointed by
                //the 'left' pointer is no longer part of the window
                windowCounts[c] -= 1;
                if( windowCounts[c] < dictT[c] ) formed--;

                //move the pointer ahead, the would help to look for a new window
                l++;
            }
            r++;
        }
        
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2]-ans[1] + 1);
    }
};

int32_t main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << "\n";
    return 0;
}
 