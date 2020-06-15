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

/*
We use recursion to search exhaustively. Key Points:

1. Make a list of all possible additions and multiplication and iterate over them 
2. Choose a subset onwhich to perform that operation.
3. Perform that operation, and call the function itself with the new parameters.
4. To prune, if we see that we have already done 2 operations and still not reached
   equality condition, just break, since 3 operaitons will, in any case, be possible.
*/

int best; const int MAXN = 100*1000+5;

inline int mulFac(int a, int b, int c, int d){
    if( b != a and (d-c)%(b-a) == 0 ){
        return (d-c)/(b-a);
    }else{
        return 1;
    }
}

inline bool equal(int* a, int* b){
    for (int i = 0; i < 3; i++)
        if( a[i] != b[i] ) return false;
    return true;
}

void solve(int* a, int* b, int num = 0){
    if( num >= best) return;
    if( equal(a,b) ){
        best = min(best,num);
        return;
    }
    if( num >= 2) return;

    set<int> add;
    add.insert(b[0]-a[0]);
    add.insert(b[1]-a[1]);
    add.insert(b[2]-a[2]);
    set<int> mult;
    for (int i = 0; i < 3; i++)
        if( a[i] != 0 and b[i]%a[i] == 0) mult.insert(b[i]/a[i]);
    mult.insert(mulFac(a[0],a[1],b[0],b[1]));
	mult.insert(mulFac(a[2],a[1],b[2],b[1]));
	mult.insert(mulFac(a[0],a[2],b[0],b[2]));
    //if both ai and bi are zero
	mult.insert(0);
    
    for (int mask = 1; mask <= 7; mask++){
        vi all;
        for (int j = 0; j < 3; j++)
        // checks if the jth bit of the counter is set
            if(mask&(1<<j))all.push_back(j);

        for( auto x: add){
            int aa[3];
            for (int j = 0; j < 3; j++) aa[j] = a[j];
            for (auto e : all) aa[e] += x;
            solve(aa, b, num+1);
        }
        for( auto x: mult){
            int aa[3];
            for (int j = 0; j < 3; j++) aa[j] = a[j];
            for (auto e : all) aa[e] *= x;
            solve(aa, b, num+1);
        }    
    }
}

//we use an exhuastive search. 
void solve(){
    best = 3;
    int a[3], b[3]; 
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    solve(a,b);
    cout << best << endl;
}



int32_t main() {
    fastIO;
    testcase(t){
        solve();
    }
    return 0;
}
 