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

int primeFactorArray(int n){
    int count = 0;
    while(n%2 == 0){
        count++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while( n%i  == 0){
            count++;
            n = n/i;
        }
    }
    if ( n > 2) count++;
    return count;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    testcase(t){
        int x, k, final;
        cin >> x >> k;
        final = primeFactorArray(x);
        if ( k <= final ){
            cout << 1 << "\n";
        }else cout << 0 << "\n";
    }
    return 0;
}
 