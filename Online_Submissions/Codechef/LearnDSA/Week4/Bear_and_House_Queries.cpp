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
    int t = 1;
    while(t--){
        // First we will find the maximum height of house, i.e. max Y
        int yHeight;
        int low = 0, high = 1001, mid = (low + (high-low)/2);
        while( mid != low && mid != high){
            cout << "? " << 0 << " " << mid << endl;
            string systemInput;
            cin >> systemInput;
            if ( systemInput == "YES"){
                low = mid;
                mid = (low + (high-low)/2);
            }
            else if ( systemInput == "NO"){
                high = mid;
                mid = (low + (high-low)/2);
            }
        }

        yHeight = mid;
        // Since its symmetric about y-axis, we only need to find max positive right point
        // We will calculate +ve x of square base
        int xSquare;
        low = 0, high = 1001, mid = (low + (high-low)/2);
        while( mid != low && mid != high){
            cout << "? " << mid << " " << 0 << endl;
            string systemInput;
            cin >> systemInput;
            if ( systemInput == "YES"){
                low = mid;
                mid = (low + (high-low)/2);
            }
            else if  ( systemInput == "NO"){
                high = mid;
                mid = (low + (high-low)/2);
            }
        }
        xSquare = mid;
        // The final step is to find the rightmost point of diagram
        int heightOfSquare = 2*xSquare, rightTriangle;
        low = xSquare, high = 1001, mid = (low + (high-low)/2);
        while( mid!= low && mid != high){
            cout << "? " << mid << " " << heightOfSquare << endl;
            string systemInput;
            cin >> systemInput;
            if ( systemInput == "YES"){
                low = mid;
                mid = (low + (high-low)/2);
            }
            else if  ( systemInput == "NO"){
                high = mid;
                mid = (low + (high-low)/2);
            }
        }
        rightTriangle = mid;
        //Now we all the necessary points;
        double areaSquare, areaTriangle;
        areaSquare = heightOfSquare*heightOfSquare;
        areaTriangle = (0.5)*(yHeight-heightOfSquare)*(rightTriangle*2);
        int ans = areaSquare + areaTriangle;
        cout << "! " << ans << "\n";
    }
    return 0;
}
 