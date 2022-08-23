#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define mod 1000000007 

int32_t main() {
    int n, target;
    cin >> n >> target;

    vector<int> c(n);
    for(int &v: c) cin >> v;

    vector<int> dp(target+1, 0);
    dp[0] = 1; //Empty set is the only way to make 0

    for (int i = 0; i <= target; i++)
        for (int j = 0; j < n; j++)
            if( i - c[j] >= 0 ){
                dp[i] += dp[i - c[j]];
                dp[i] %= mod;
            }
        
    cout << dp[target] << "\n";
    
    return 0;
}
 