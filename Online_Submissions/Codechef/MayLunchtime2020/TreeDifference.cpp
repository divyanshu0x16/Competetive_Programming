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

int n, q; const int N = 200005; int arr[N], depth[N], parent[N]; vi adj[N];

void dfs(int curr, int prev1 = -1, int depth1 = 0){
    parent[curr] = prev1;
    depth[curr] = depth1;

    for (auto &&x : adj[curr])
    {
        if( x != prev1){
            dfs(x, curr, depth1 + 1);
        }
    }
}

int solve(int a, int b){
    int freq[105];
    memset(freq, 0, sizeof(freq));
    while(a != b){
        if( depth[a] > depth[b]){
            freq[arr[a]]++;
            if ( freq[arr[a]] > 1)
                return 0;
            a = parent[a];
        }else{
            freq[arr[b]]++;
            if(freq[arr[b]] > 1)
                return 0;
            b = parent[b];
        }
    }
    // This is for the common root node of both
    freq[arr[a]]++;
    if(freq[arr[a]] > 1)
        return 0;
    // We have mantained a freq array. Now we check for all set values in array and find
    // the minimum difference.
    int prev1 = -200;
    int res = 105;
    for (int i = 1; i <= 100; i++)
    {
        if(freq[i]){
            res = min(res, i - prev1);
            prev1 = i;
        }
    }
    return res;
}

int32_t main() {
    fastIO;
    testcase(t){
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            adj[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        while(q--){
            int a, b;
            cin >> a >> b;
            cout << solve(a, b) << "\n";
        }
    }
    return 0;
}
