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
        int n, r; cin >> n >> r;
        int u, v, w;
        
        vector< vector < int > > graph(n, vector< int > (n, INT32_MAX));

        for (int i = 0; i < r; i++)
        {
            cin >> u >> v >> w; 
            u--; v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        for (int i = 0; i < n; i++)
            graph[i][i] = 0;

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if( graph[i][k] + graph[k][j] < graph[i][j])
                        graph[i][j] = graph[i][k] + graph[k][j];

        
        vector < int > costs(n); 
        for (auto &&i : costs)
            cin >> i;

        vector< vector < int > > graphCosts(n, vector< int > (n, INT32_MAX));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graphCosts[i][j] = costs[i]*graph[i][j];
        
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if( graphCosts[i][k] + graphCosts[k][j] < graphCosts[i][j])
                        graphCosts[i][j] = graphCosts[i][k] + graphCosts[k][j];
        
        int p, q; cin >> p >> q;
        cout <<  graphCosts[--p][--q] << "\n";

    }
    return 0;
}
 