#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
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

void count_sort(vector<int> &p, vi &c){
    int n = p.size();
    {
        vi cnt(n);
        for (auto &&x : c)
        {
            cnt[x]++;
        }
    
        vi p_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i-1] + cnt[i-1];
        }

        for(auto x: p){
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        } 
        p = p_new;
    }
}


int32_t main() {
    fastIO;
    int t = 1;
    while(t--){
        string s;
        cin >> s;
        s += "$";
        int n = s.size();
        // C will store the equivalance classes
        vector<int>  p(n), c(n);
        {
            // k = 0
            vector<pair<char, int> > a(n);
            for (int i = 0; i < n; i++) a[i] ={s[i], i};
            sort(a.begin(), a.end());
            
            for (int i = 0; i < n; i++) p[i] = a[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; i++){
                if( a[i].first == a[i-1].first ){
                    c[p[i]] = c[p[i-1]];
                }else{
                    c[p[i]] = c[p[i-1]] + 1;
                } 
            }
        }

        int k = 0;
        while ((1<<k) < n)
        {
            // k -> k+1
            
            for (int i = 0; i < n; i++){
                p[i] = (p[i] - (1 << k) +n)%n;
            }

            count_sort(p, c);

            vi c_new(n);
            c_new[p[0]] = 0;
            for (int i = 1; i < n; i++){
                pii prev = {c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
                pii now = {c[p[i]], c[(p[i]+(1<<k))%n]};
                if( now == prev){
                    c_new[p[i]] = c_new[p[i-1]];
                }else{
                    c_new[p[i]] = c_new[p[i-1]] + 1;
                }    
            }
            c = c_new;
            k++;
        }
        
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
 