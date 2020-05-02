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
        int n, q; cin >> n >> q;
        string str; cin >> str;
        map < char, int > freq_map;
        for (int i = 0; i < n; i++) 
            freq_map[str[i]]++;

        map <int, int> numberMap;
        auto it = freq_map.begin();
        while (it != freq_map.end()){
            numberMap[it -> second]++;
            it++;
        }
        
        for (int i = 0; i < q; i++)
        {
            int c; cin >> c;
            int peoplePending = 0;
            
            for( pair<int, int> element: numberMap ){
                if ( (c-element.first) >= 0 )
                    continue;
                else if ( (c-element.first) < 0)
                    peoplePending += (element.first -c)*element.second;
            }

            cout << peoplePending << "\n";
        }
    }
    return 0;
}
 