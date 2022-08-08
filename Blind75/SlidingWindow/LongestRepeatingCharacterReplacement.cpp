#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;

        int i = 0;
        int j = 0;

        int result = 0;

        while (j < s.size())
        {
            count[s[j] - 'A']++; //increase the freq;
            maxCount = max(maxCount, count[s[j] - 'A']); //Since we DONT replace the maxElement in current window
            while(j - i + 1 - maxCount > k){ //keep decreasing the i pointer
                count[s[i] - 'A']--; //Since we are moving the left pointer, we have to decrese the freq
                i++;
                //The window only changes when maxCount will change :- https://www.youtube.com/watch?v=gqXU1UyA8pk
            }
            result = max(result, j-i+1);
            j++;
        }

        return result; 
    }
};

int32_t main() {
    return 0;
}
 