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
#define rep(i,n)      for (int i = 0; i < n; i++)
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
        // Initialize Input
        int k, q; cin >> k >> q;
        int maxquery = 0;
        int motivation[k], satisfaction[k];
        rep(i, k) cin >> motivation[i];
        rep(i, k) cin >> satisfaction[i];
        // Sort both the arrays
        sort(motivation, motivation+k);
        sort(satisfaction, satisfaction+k);
        // Queries
        priority_queue<int> pq;
        vector<int> v;

        rep(i, k){
            rep(j, k){
                if ( pq.size() < 10000) pq.push(motivation[i]+satisfaction[j]);
                else if ( motivation[i]+satisfaction[j] < pq.top()){
                    pq.pop();
                    pq.push(motivation[i]+satisfaction[j]);
                }
                else break;
                }
            }

        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        } 
        reverse(v.begin(), v.end());
        while(q--){
            int d;
            cin >> d;
            cout << v[d-1] << "\n";
        }

    }
    return 0;
}
 