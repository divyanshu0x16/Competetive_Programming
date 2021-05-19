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

        vi array(n);
        for (auto &&i : array)
            cin >> i;  

        vi inversions(n, 0); // inversion[i] denotes the no. of pairs the ith element of array is involved in
        int totalInversions = 0;

        //Counting the number of pairs i is involved in 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++)
                if(array[j] > array[i]) inversions[i]++;

            for (int j = i+1; j < n; j++)            
                if(array[i] > array[j]) inversions[i]++;

            totalInversions += inversions[i];
        }
        totalInversions /= 2;

        //Now we will creat a DP array
        //DP[i][j] will be true if a sum value 'j' could be achieved can be achieved from arr[0....i]
        vector <vector < bool > > DP(n+1, vector < bool > (totalInversions+1, 0));


        if( totalInversions == 0 ) {
            cout << "YES" << "\n";
            continue;
        }

        for (int i = 0; i <= n; i++)
            DP[i][0] = 1; //If the sum is zero then the answer is already true

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= totalInversions; j++){
                if( j < inversions[i-1] )
                    DP[i][j] = DP[i-1][j];
                if( j >= inversions[i-1] )
                    DP[i][j] = DP[i-1][j] or DP[i-1][j - inversions[i-1]];        
            }
        }

        if ( DP[n][totalInversions] ) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
 