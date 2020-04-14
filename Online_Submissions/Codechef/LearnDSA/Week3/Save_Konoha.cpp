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


int32_t main() {
    fastIO;
    testcase(t){
        int n; int k; int ans = 0; bool flag = 0;
        cin >> n >> k;
        pqi powersSoldiers;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            powersSoldiers.push(input);
        }
        while ( k > 0){
            if ( powersSoldiers.top() == 0) {
                flag = 1;
                break;
            }
            else {
                k = k - powersSoldiers.top();
                int reactionPower = powersSoldiers.top();
                reactionPower /= 2;
                powersSoldiers.pop();
                powersSoldiers.push(reactionPower);
                ans++ ;
            }
        }
        if ( flag == 1 ){
            cout << "Evacuate" << "\n";
        }else {
            cout << ans << "\n";
        }
    }
    return 0;
}
 