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

vi v, v1;
int dp[1000010];

int solve(){
    dp[0] = 0;
    dp[1] = 1e9;
    dp[2] = v[1] - v[0];

    for (int i = 2; i < v.size(); i++){
        dp[i+1] = min(v[i]-v[i-1]+dp[i-1], v[i]-v[i-2]+dp[i-2]);
    }

    return dp[v.size()];
    
}

int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n;
        v.clear();

        for (int i = 1; i <= n; i++){
            int x; cin >> x;

            if(x==1)
                v.push_back(i);
        }

        if(v.size() == 0){
            cout << 0 << "\n";
            continue;
        }

        if( v.size() == 1){
            cout << -1 << "\n";
            continue;
        }

        int ans = 1e9;

        ans = min(ans, solve());

        v1.clear();
        v1.push_back(1);
        for (int i : v)
            v1.push_back(n-v.back()+1+i);
        v1.pop_back();
        v = v1;
        ans = min(ans, solve());

        v1.clear();
        v1.push_back(1);
        for (int i : v)
            v1.push_back(n-v.back()+i+1);
        v1.pop_back();
        v = v1;
        ans = min(ans, solve());

        cout << ans << "\n";
    }
    return 0;
}
 