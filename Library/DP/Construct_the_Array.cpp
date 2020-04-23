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

const int MOD = 1000000007;
// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    vector<long long> b(n), a(n);

    a[0] = x == 1 ? 1 : 0;
    b[0] = x == 1 ? 0 : 1;

    for(int i = 1; i < n; ++i){
        a[i] = b[i-1]%MOD;
        b[i] = (a[i-1]*(k-1) + b[i-1]*(k-2)) % MOD;
    }

    return a[n-1];
}

int32_t main() {
    fastIO;
    int t = 1;
    while(t--){
        int n, k, x; cin >> n >> k >> x;
        cout << countArray(n, k, x) << endl;
    }
    return 0;
}
 