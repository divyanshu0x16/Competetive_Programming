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

template < class I >
auto get_kth_element_count( I it, int offset){
    while ( offset >= it -> second)
        offset -= it->second, ++it;
    return it->second;
}

int calculate_F( map<int , int> const& m, int n, int offset){
    if( offset < n - offset){
        return get_kth_element_count(m.rbegin(), offset);
    }else{
        offset = n - offset - 1;
        return get_kth_element_count(m.begin(), offset);
    }
}

int solve(vector<int> const& v, int n, int k){
    int ans = 0;
    for (int i = 0; i < n; i++){
        map < int, int > ms;
        for (int j = i, s = 1; j < n; ++j, ++s){
            ms[v[j]]++;
            int m = ceil(k/float(s));
            int offset = (m*s - k)/m;
            int F = calculate_F(ms, s, offset);
            if(ms.count(F)) ans++; 
        }
    }
    return ans;
}

int32_t main() {
    fastIO;
    testcase(t){
        int n; int k; cin >> n >> k;
        vector <int> vec;
        for (int i = 0; i < n; i++)
        {
            int Ai;
            cin >> Ai;
            vec.push_back(Ai);
        }
        cout << solve( vec, n, k) << "\n";
    }
    return 0;
}
 