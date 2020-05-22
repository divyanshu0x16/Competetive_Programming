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

int disroot(int x){
    int ctr = 0;
    while(x>0){
        x/=2;
        ++ctr;
    }
    return ctr;
}

int lca(int x, int y){
    if(x==y)
        return x;
    else{
        set<int> X,Y;
        while(x>0){
            X.insert(x);
            x/=2;
        }
        while(y>0){
            Y.insert(y);
            y/=2;
        }
        int ans = 1;
        for (auto i = X.begin() ; i != X.end(); i++){
            if(Y.find(*i) != Y.end())
                ans = max(ans, *i);
        }
        return ans;
    }
}

int numnodes(int x, int y){
    return (disroot(x)+disroot(y)-2*disroot(lca(x,y)) + 1);
}

int32_t main() {
    fastIO;
    int t =1;
    while(t--){
        int q; cin >> q;
        string s; 
        int ct = 0, x, y;
        int r, b;
        b=1, r=0;

        while (q--){
            cin >> s;
            if(s == "Qi"){
                swap(r,b);
            }
            else{
                cin >> x >> y;
                if(numnodes(x,y)%2==0)
                    cout << numnodes(x,y)/2 << " ";
                else{
                    int odd = numnodes(x,y)/2 +1;
                    int even = numnodes(x,y)/2;
                    if(s=="Qb"){
                        if(b==disroot(x)%2)
                            cout << odd << " ";
                        else 
                            cout << even << " ";
                    }
                    else{
                        if(r==disroot(x)%2)
                            cout << odd << " ";
                        else 
                            cout << even << " ";
                    }
                }  
            }
        }     
    }
    return 0;
}
 