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

const int maxm = 1000000;
int father[maxm], s[maxm];

int find(int x){
    int y =x;
    while(x != father[x]){
        x = father[x];
    }
    for(; y!=x;){
        int t = father[y];
        father[y] = x;
        y = t;
    }
    return x;
}

int32_t main() {
    fastIO;
    testcase(t){
        int n, q;
        cin >> n;
        assert(1 <= n && n <= maxm);
        for (int i = 0; i < n; i++){
            cin >> s[i];
            father[i] = i;
        }
        cin >> q;
        for (int i = 0; i < q; i++){
            int op, x, y;
            cin >> op;
            if(op == 0){
                cin >> x >> y;
                --x; --y;
                int fx = find(x), fy = find(y);
                if ( fx == fy){
                    cout << "Invalid query!" << "\n";
                }else{
                    if(s[fx]>s[fy]){
                        father[fy] = fx;
                    }else if ( s[fx] < s[fy]){
                        father[fx] = fy;
                    }
                }
            }else{
                cin >> x;
                cout << find(x-1) << "\n";
            }
        }
    }
    return 0;
}
 