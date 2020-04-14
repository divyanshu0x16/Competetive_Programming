#include <bits/stdc++.h>
using namespace std;

#define int           long long 
#define rep(i,n)      for ( int i = 0; i < n; i++) 
#define REP(i,k,n)    for ( int i = k; i <= n; i++) 
#define REPR(i,k,n)   for ( int i = k; i >= n; i--)
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
        int n, ans = 0;
        cin >> n;
        int arr[n];
        rep(i , n){
            cin >> arr[i];
        }
        sort(arr, arr+n, greater<int>());
        for (int i = 0; i < n; i++)
        {
            if ( (arr[i] - (i)) <= 0) continue;
            else ans += arr[i]-(i);
        }
        cout << ans%mod << "\n";
    }
    return 0;
}
