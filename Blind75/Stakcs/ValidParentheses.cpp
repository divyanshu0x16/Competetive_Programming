#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;

        if(s.length() == 1) return false;

        map<char, char> open_close;
        open_close['('] = ')';
        open_close['{'] = '}';
        open_close['['] = ']';

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
                brackets.push(s[i]);
            else{
                if( !brackets.empty() and open_close[brackets.top()] == s[i] ) brackets.pop();
                else return false;
            }
        }
        
        if(brackets.empty() ) return true;
        else return false;

        return true;
    }
};

int32_t main() {
    Solution s;
    cout << s.isValid("){") << "\n";
    return 0;
}
 