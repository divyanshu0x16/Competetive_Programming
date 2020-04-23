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

int minDiff( vi array, int n){
    int diff = INT_MAX;
    rep(i, n-1){
        if ((array[i+1]-array[i]) < diff) diff = array[i+1] - array[i];
    }
    return diff;
}



int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    testcase(t){
        int n; cin >> n;
        int arr[n];
        vi index;
        rep(i, n){
            cin >> arr[i];
            if ( arr[i] == 1) index.push_back(i);
        }
        int diff = minDiff(index, index.size());
        if ( diff < 6) cout << "NO" << "\n";
        else if ( index.size() == 1 ) cout << "YES" << "\n";
        else cout << "YES" << "\n";
    }

    return 0;
}
 