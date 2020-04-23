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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //Input
        bool state;
        if ( a[0] < 0 ) state = false;
        else state = true;
        int maxPositive = 0, minNegative = -INFINITY;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {   
            if ( a[i] < 0 && state == true){
                sum += maxPositive;
                state = false;
                minNegative = -INFINITY;
            }
            else if ( a[i] >= 0 && state == false){
                sum += minNegative;
                state = true;
                maxPositive = 0;
            }

            if ( state == true){
                if ( a[i] > maxPositive){
                    maxPositive = a[i];
                }
            }
            else if ( state == false){
                if (  a[i]> minNegative ){
                    minNegative = a[i];
                }
            }
        }
        if ( a[n-1] < 0) sum += minNegative;
        else sum += maxPositive;
        cout << sum << "\n";
    }
    return 0;
}
 