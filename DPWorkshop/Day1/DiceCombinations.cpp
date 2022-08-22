#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

#define mod 1000000007 

using namespace std;
using namespace __gnu_pbds;

//https://japlslounge.com/posts/cses/dice_combinations/1.htm

vector<int> dp(1000001, 0);

int diceCombinations(int left){

    if(dp[left] != 0) return dp[left];

    for (int i = 1; i <= 6; i++)
        if( left - i >= 0){
            dp[left] += diceCombinations(left-i);
            dp[left] %= mod;
        }
    
    return dp[left];
}

int32_t main() {
    int n;
    cin >> n;
    dp[0] = 1;
    cout << diceCombinations(n) << "\n";
    return 0;
}
 

