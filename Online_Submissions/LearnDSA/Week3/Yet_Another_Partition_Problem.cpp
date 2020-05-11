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

const int inf = 1e18;
const int N = 1e6+100;

int n, m, arr[N];

int32_t main() {
    fastIO;
    int t = 1;
    while(t--){
        cin >> n >> m;
        assert(n<=1e6); assert(m<=2e5);
        arr[0]=inf; set<int> start;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            assert(arr[i]<=1e6);
            if( arr[i]%arr[i-1] !=0 ){
                start.insert(i);
            }
        }
        arr[n+1] = mod;
        while(m--){
            int t; cin >> t; assert( t==1 || t==2);
            if ( t == 1){
                int ind, val; cin >> ind >> val;
                assert( ind <= n); assert( val <= 1e6 );
                arr[ind] = val;
                if( arr[ind]%arr[ind-1] != 0 ) start.insert(ind);
                else start.erase(ind);
                if ( arr[ind+1]%arr[ind] != 0 ) start.insert(ind+1);
                else start.erase(ind+1);
            }
            else
            {
                int ind; cin >> ind;
                auto it = start.upper_bound(ind);
                it--;
                cout << (*it) << "\n";
            }      
        }
    }
    return 0;
}
 