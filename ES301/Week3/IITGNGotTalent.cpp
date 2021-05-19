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

int find_set(int v, vi &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int x, int y, vi &parent, vi &score){
    int a = find_set(x, parent);
    int b = find_set(y, parent);
    if( a == b){
        cout << "Invalid query!" << "\n";
    }else if( score[a] != score[b]){
        if( score[a] < score[b] ){
            parent[a] = b;
        }else{
            parent[b] = a;
        }
    }
}

int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n; vi score(n+1, 0);

        for (int i = 1; i <= n; i++)
            cin >> score[i];
        
        
        vi parent(n+1, -1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        int q; cin >> q;
        int type, x, y;
        while (q--){
            cin >> type;
            if(type == 0){
                cin >> x >> y;
                union_sets(x, y, parent, score);
            }else{
                cin >> x;
                int ans = find_set(x, parent);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
 