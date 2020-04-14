#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    testcase(t){
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
            cout << 1 << " " << 1 << "\n";
        }
        else if (n == 2){
            cout << 1 << "\n";
            cout << 2 << " " << 1 << " " << 2 << " " << "\n";
        }
        else if (n == 3) {
            cout << 1 << "\n";
            cout << 3 << " " << 1 << " " << 2 << " " << 3 << "\n";
        }
        else {
            cout << floor(n/2) << "\n";
            cout << 3 <<  " " << 1 << " " << 2 << " " << 3 << "\n";
            for (int i = 4; i <= n-1; i = i+2)
            {
                cout << 2 << " " << i << " " << i + 1 << "\n";
            } 
            if ( n%2 == 0) cout << 1 << " " << n << "\n";  
        }   
    }
    return 0;
}
 