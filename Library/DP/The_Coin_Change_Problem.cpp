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

int c[52];
int numCoins;
long long table[52][252];
bool calculated [52][252];

long long solve(int i, int make){
    if(make < 0) return 0;
    if(make == 0) return 1;
    if(i > numCoins) return 0;
    if(calculated[i][make] == false){
        table[i][make] = solve(i, make - c[i]) + solve(i+1, make);
        calculated[i][make] = true;
    }
    return table[i][make];
}

int32_t main() {
    fastIO;
    int t = 1;
    while(t--){
        int make;
        cin >> make >> numCoins;
        for (int i = 1; i <= numCoins; i++)
        {
            cin >> c[i];
        }
        cout << solve(1, make) << "\n";
    }
    return 0;
}
 
