#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define modulo(a, b)  (a%b<0 ? a%b+b : a%b)
#define all(x)        (x).begin(), (x).end()
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ordered_set   tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

// We use prefix sum array in this 
int32_t main() {
    fastIO;
    testcase(t){
        // Step 1 :- Taking Input
        int n, k;
        cin >> n >> k;
        vector <int> givenArray(n);
        for (auto &&it : givenArray) cin >> it;
        // Step 2 :- We maintain a freq map of all the sum possibles
        vector <int> countOfSum(2*k+1);
        for (int i = 0; i < n/2; ++i)
        {
            ++countOfSum[givenArray[i] + givenArray[n-i-1]];
        }
        // Step 3 :- Now we do prefix sum array
        vector <int> prefixSum(2*k+2);
        for (int i = 0; i < n/2; ++i)
        {
            // We do range with require one operations
            int leftOfRange = 1 + givenArray[i], leftOfRange2 = k + givenArray[i];
            int rightOfRange = 1 + givenArray[n-i-1], rightOfRange2 = k + givenArray[n-i-1];
            // We are creating a range here, so max of left should always be less than equal to min of right
            assert(max(leftOfRange, leftOfRange2) <= min(rightOfRange, rightOfRange2));
            //Prefix Sum for calculating one operation in O(1) time
            ++prefixSum[min(leftOfRange, leftOfRange2)];
            --prefixSum[max(rightOfRange, rightOfRange2)+1];
        }
        // Step 4 :- We finalize the prefixSum array
        for (int i = 1; i <= 2*k + 1; i++)
        {
            prefixSum[i] += prefixSum[i-1]; 
        }
        // Step 5 :- Calculate the ans!!!!
        int ans = 1e9;
        for (int sum = 2; sum <= 2*k; sum++)
        {
            /* We need minimum number of operations, for all possible values of sum, i.e. 
            between 2 and 2*k */
            /* We do (prefixSum[sum]-countOfSum[sum]) because prefixSum tekes both
            0 and 1 operations into consideration.
            We do (n/2-prefixSum[sum])*2, because total no. of pairs will be n/2
            but no. of operations for each pair is 2.*/
            ans = min(ans, (prefixSum[sum]-countOfSum[sum]) + (n/2-prefixSum[sum])*2);
        }
        cout << ans << "\n";
    }
    return 0;
}
 