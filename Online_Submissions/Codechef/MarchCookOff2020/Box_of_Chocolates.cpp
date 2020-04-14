#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
//#define int           long long 
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
        int n; cin >> n;
        // Input and Maximum
        int array[n+1];
        int maximum = 0;
        for (int i = 1; i <= n; i++){
            cin >> array[i];
            if ( array[i] > maximum ){
                maximum = array[i];
            }
        }
       
        vector <int> pos;
        for (int i=1; i<=n ; i++){
             if ( array[i] == maximum ){
                pos.push_back(i);
             }
        }
        // Our array is cyclic, so get the realtion between last and first element
        pos.push_back(pos[0]+n);

        int ans = 0;
        int sz = n/2;
        // If difference is greater than, we can fit an array of size n/2
        for ( int i = 1; i < pos.size(); i++) ans += max(0, pos[i] - pos[i-1] - sz);

        cout << ans << "\n";
    }
    return 0;
}
 