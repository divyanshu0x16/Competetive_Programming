#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
//#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define all(x)        (x).begin(), (x).end()
#define modulo(a, b)  (a%b<0 ? a%b+b : a%b)
#define intpow(a,b)   (int)(pow(a,b) + 0.5)
#define gcd(a,b)      __gcd(a, b)
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

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second < b.second); 
}

int32_t main() {
    int t; scanf("%d", &t);
    while(t--){
        int n, k; scanf("%d %d", &n, &k);

        map<int, vector<pair < int, int > > >  input;
        for (int i = 0; i < n; ++i){
            int si, fi, pi; scanf("%d %d %d", &si, &fi, &pi);
            input[pi].push_back({si, fi});
        }

        int answer = 0;
       
        for (auto &&i : input)
        {
            vector< pair <int, int > > current = i.second;
            sort(all(current), sortbysec);

            int previousTime = -1;
            for (int j = 0; j < current.size(); ++j)
                if (current[j].first >= previousTime){
                    answer++;
                    previousTime = current[j].second;
                }
        }
        
        
        cout << answer << "\n";
    }
    return 0;
}
 