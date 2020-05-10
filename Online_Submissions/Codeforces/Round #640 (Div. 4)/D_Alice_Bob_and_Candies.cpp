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
        vi a(n);
        for( auto &it: a) cin >> it;
        int l = 0, r = n -1;
        int suml = 9, sumr = 0;
        int cnt = 0, ansl = 0, ansr = 0;
        while(l <= r){
            if (cnt%2 ==0){
                int nsuml = 0;
                while (l <=r && nsuml <= sumr)  
                {
                    nsuml += a[l++];
                }
                ansl += nsuml;
                suml = nsuml;
            }else{
                int nsumr = 0;
                while (l <= r && nsumr <= suml )
                {
                    nsumr += a[r--];
                }
                ansr += nsumr;
                sumr = nsumr;
            }
            ++cnt;
        } 
        cout << cnt << " " << ansl << " " << ansr << "\n";
    }
    return 0;
}
 