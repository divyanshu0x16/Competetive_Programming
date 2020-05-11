#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0)
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
    int x = 1;
    while(x--){
        int n; int k;
        cin >> n >> k;
        int que_chefs[n];
        /* for each index i, we try to find the first index j where (j>i) and arr[j]<arr[i]
        if no such j exist, ignore that i*/
        for (int i = 0; i < n; i++) cin >> que_chefs[i];
        int ans = 1;
        stack < pii > st;
        for (int i = 0; i < n; i++)
        {
            /* code */
            while (!st.empty() && st.top().first > que_chefs[i])
            {
                /* code */
                pii element = st.top();
                int fearfullness = i - element.second + 1;
                ans *= fearfullness;
                ans = ans%mod;
                st.pop();
            }   
            st.push(make_pair(que_chefs[i], i));
        }
        std::cout << ans << "\n";
        
    }
    return 0;
}
 