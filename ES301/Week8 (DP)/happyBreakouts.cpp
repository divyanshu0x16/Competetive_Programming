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
typedef map<int, int> mii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

int calculateTalks(mii &frequencies, vi &array, int index, int &talks){
    frequencies[array[index]] += 1;
    if( frequencies[array[index]] == 2 ) talks += 2; //The first time the freq is 2, we will have 2 clashes
    else if( frequencies[array[index]] >= 2) talks += 1; //Then the no of clashes will just increase by one

    return talks;
}

int smallestInefficiency(vi &array, vi &dp, int n, int k){
    for (int i = 1; i <= n; i++)
    {
        // This will be the max possible inefficieny at the ith table and we will find the minimum from this
        dp[i] = dp[i-1] +k; //We will create a seperate breakout room for ith person. 
        mii freq;
        int talk = 0;

        for (int j = i; j >= 1; j--)
        {
            calculateTalks(freq, array, j, talk);
            //Recurrence relation. We will try every possible combination of rooms, and will pick the minimum one
            dp[i] = min(dp[i], k + dp[j-1] + talk); 
        }
    }
    return dp[n];
}

int32_t main() {
    fastIO;
    testcase(t){
        int n, k; cin >> n >> k;
        vi array(n+1);

        for (int i = 1; i <= n; i++)
            cin >> array[i];

        vi dp(n+1, 0);
        cout << smallestInefficiency(array ,dp, n, k) << "\n";
    }
    return 0;
}
 