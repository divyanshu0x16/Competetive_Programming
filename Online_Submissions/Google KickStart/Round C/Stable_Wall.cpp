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

string ans;
vi adj[26];
bool vis[26], act[26];
bool bad;

void dfs(int u){
    act[u] = 1;
    vis[u] = 1;
    for(int v: adj[u]){
        if(act[v]&&v^u)
            bad=1;
        else{
            if(!vis[v])
                dfs(v);
        }
    }
    act[u]=0;
    ans += (char)(u+'A');
}

int32_t main() {
    fastIO;
    int w = 1;
    testcase(t){
        int r, c; cin >> r >> c;
        set<char> allCharactersAppear;
        string wall[r*c];
        for (int i = 0; i < r; i++)
        {
            cin >> wall[i];
            for(char c: wall[i])
                allCharactersAppear.insert(c);
            if(i){
                for(int j=0; j<c; ++j)
                    adj[wall[i-1][j]-'A'].push_back(wall[i][j]-'A');
            }   
        }
        memset(vis, 0, 26);
        memset(act, 0, 26);
        ans = "";
        bad = 0;
        for(char c: allCharactersAppear)
            if(!vis[c-'A'])
                dfs(c-'A');
        if(bad)
            ans="-1";
        for (int i = 0; i < 26; i++)
            adj[i].clear();
        cout << "Case #" << w << ": " << ans << "\n";
        w++;
    }
    return 0;
}
 