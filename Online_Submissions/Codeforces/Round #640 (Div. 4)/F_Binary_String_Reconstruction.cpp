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
#define intpow(a,b)   (int)(pow(a,b) + 0.5)
#define gcd(a,b)      __gcd(a, b)
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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if ( n1 == 0){
            if ( n0 != 0){
                cout << string(n0+1, '0') << endl;
            }else{
                cout << string(n2+1, '1') << endl;
            }
            continue;
        }
        string ans;
        for (int i = 0; i < n1 +1; i++)
        {
            if ( i&1) ans += "0";
            else ans += "1";
        }
        ans.insert(1, string(n0, '0'));
        ans.insert(0, string(n2, '1'));
        cout << ans << "\n";
    }
    return 0;
}
 