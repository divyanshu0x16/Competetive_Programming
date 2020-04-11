#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
        int n; int k;
        cin >> n >> k;
        stack < pii > queue;
        int ans = 1;
        int x;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            while ( !queue.empty() && queue.top().first > x){
                auto y = q.top();
                q.pop();
                
            }
        }
        

    }
    return 0;
}
 