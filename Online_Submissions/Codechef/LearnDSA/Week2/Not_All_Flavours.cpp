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
        map <int , int > last;
        int a[n];
        for (int i = 0; i < n; i++){
            /* code */
            cin >> a[i];
            // At first no elements have appeared
            last[a[i]] = -1;
        }
        // Agar size k se kam hui matlab koi value missing hai.
        if ( last.size() < k){
            cout << n << "\n";
            continue;
        }
        // store all last occurences in set
        set< array < int, 2 > > s;
        for ( auto p : last)
        {
            s.insert({p.second, p.first});
        }

        // fix right end of subarray
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            s.erase({last[a[i]], a[i]});
            last[a[i]] = i;
            s.insert({last[a[i]], a[i]});
            //
            ans = max(i - (*s.begin())[0], ans);
        }
        cout << ans << "\n";  
    }
    return 0;
}
 