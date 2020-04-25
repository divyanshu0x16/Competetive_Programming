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


int32_t main() {
    fastIO;
    testcase(t){
        int n, k; cin >> n >> k;
        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        int sortedArray[n];
        for (int i = 0; i < n; i++)
        {
            sortedArray[i] = array[i];
        }
        sort(sortedArray, sortedArray+n);
        map< int, vector < int > > loopUp;
        for (int i = 0; i < n; i++)
        {
            loopUp[sortedArray[i]].push_back(i);
        }
        bool flag;
        for (int i = 0; i < n; i++)
        {
            flag = false;
            int val = array[i];
            for (int j = 0; j < loopUp[val].size(); j++)
            {
                if( abs((i+1)-(loopUp[val][j]+1))%k == 0){
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
            }
            if (flag == false) break;
        }
        if ( flag == false) cout << "no" << "\n";
        else cout << "yes" << "\n"; 
    }
    return 0;
}
 