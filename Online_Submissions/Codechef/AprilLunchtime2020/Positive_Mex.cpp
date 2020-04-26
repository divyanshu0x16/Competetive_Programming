#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
//#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
//#define mod           998,244,353 
#define modulo(a, b)  (a%b<0 ? a%b+b : a%b)
#define intpow(a,b)   (int)(pow(a,b) + 0.5)
#define rep(i,n)      for (int i = 0; i < n; i++)
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

const long long mod = 998244353;
long long power[100005];
 
int main(){
    int t;
    cin >> t;
 
    // precompute 2^ns (upto max value of n = 10^5)
    power[0] = 1;
    for(int i = 1; i < 100005; i++){
        power[i] = (2*power[i-1])%mod;
    }
 
    while(t--){
        int n;
        cin >> n;
        long long input[n];
        unordered_map<long long, long long> count;
 
        //input + update map
        for(int i = 0; i < n; i++){
            cin >> input[i];
            count[input[i]]++;
        }
 
        long long ans = 0, sum = 0, prod =1;
        long long newMex;
        for(int mex = 1; mex <= n+1; mex++){
 
            // running sum = num 1s + num2s +...numXs
            sum = (sum + count[mex])%mod;
 
            newMex = (mex*prod)%mod;
            newMex = (newMex*power[n-sum])%mod;
 
            //update answer
            ans = (ans + newMex)%mod;
 
            // running prod = [2^(num 1s) - 1]*....
            prod = (prod*(power[count[mex]]-1))%mod;
        }
        cout << ans << endl;
 
    }
}
