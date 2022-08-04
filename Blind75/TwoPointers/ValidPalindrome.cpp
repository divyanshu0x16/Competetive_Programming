#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // convert string to lowercase and remove alphanumeric characters

        for (int i = 0; i < s.length(); i++)
            s[i] = tolower(s[i]);
        s.erase(remove(s.begin(), s.end(), ' '), s.end()); // to remove spaces
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](auto const &c) -> bool
                               { return !std::isalnum(c); }),
                s.end());

        // check if it is a palindrome using two pointers
        for (int i = 0, j = s.length() - 1; i < s.length(), j >= 0; i++, j--)
        {
            if (i > j)
                break;
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};

int32_t main()
{
    Solution s;
    cout << s.isPalindrome(".......a.....") << "\n";
    return 0;
}
