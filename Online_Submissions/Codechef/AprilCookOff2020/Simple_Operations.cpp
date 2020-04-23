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
/*1. Find initial K and L
2. Find gaps, add them to a vector, and sort them
3. Iterate through and find updated values of K and L
and take the minimu
*/

int32_t main() {
    fastIO;
    testcase(t){
        string a, b;
        cin >> a >> b;
        int n = a.size();

        // Steps 1 and 2
        int L = 0, K = 0;
        int gapLength = 0;
        vi gaps;
        bool canDoGaps = 0;

        for (int i = 0; i < n; i++)
        {
            if(a[i]==b[i]){
                if(canDoGaps) gapLength++;
            }
            else{
                if(!canDoGaps)K++;
                L++;
                canDoGaps = true;
                if( gapLength > 0){
                    K++;
                    gaps.push_back(gapLength);
                    gapLength = 0;
                }
            }
        }

        sort(all(gaps));
        //Step 3: Iterate through the vector and update K and L
        int ans = L*K;
        for (auto gapLength : gaps)
        {
            K--;
            L+= gapLength;
            ans = min(ans, L*K);
        }
        cout << ans << "\n";
    }
    return 0;
}
 