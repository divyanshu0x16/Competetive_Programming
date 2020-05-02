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
        int n; cin >> n;
        int given[n];
        for (auto &&i : given) cin >> i;

        vector<int> perCaseInfection;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = i; j < n-1; j++)
            {
                int dist = abs(given[j]-given[j+1]);
                if ( abs(given[j]-given[j+1]) <= 2) count++;
                else if ( abs(given[j]- given[j+1]) > 2) break;
            }

            for (int j = i; j > 0; j--)
            {
                int dist = abs(given[j]-given[j-1]);
                if ( abs(given[j] - given[j-1]) <= 2) count++;
                else if ( abs(given[j] - given[j-1]) > 2) break; 
            }
            
            perCaseInfection.push_back(count);
        }
        

        cout << *min_element(all(perCaseInfection)) << " " << *max_element(all(perCaseInfection)) << "\n";
    }
    return 0;
}
 