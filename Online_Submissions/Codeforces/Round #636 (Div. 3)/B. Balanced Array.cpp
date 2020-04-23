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


int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n;
        n = n/2;
        if ( n%2 != 0) cout << "NO" << "\n";
        else {
            int sum_even = 0, sum_odd = 0;
            cout << "YES" << "\n";
            for (int i = 2; i <= 2*n; i += 2)
            {
                cout << i << " ";
                sum_even += i;
            }
            for (int i = 0; i < n-1; i++)
            {
                cout << 2*i+1 << " ";
                sum_odd += 2*i+1;
            }
            cout << (sum_even-sum_odd) << "\n";
        }
    }
    return 0;
}
 