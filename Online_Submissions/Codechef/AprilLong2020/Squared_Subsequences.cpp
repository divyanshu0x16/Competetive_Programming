#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;


int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n; int total = (n*(n+1))/2;
        int givenArray[n];
        vi indexof2;
        for (int i = 0; i < n; i++)
        {
            int Ai; cin >> Ai;
            if ( Ai < 0) Ai = (Ai)*(-1);
            if ( Ai%4 == 2 ) indexof2.push_back(i);
            givenArray[i] = Ai%4;
        }
        int sum = 0;
        for ( auto i : indexof2)
        {
            int leftCount = 1; int rightCount = 1;
            for (int j = i-1; j >= 0; j--)
            {
                if( givenArray[j] == 1 || givenArray[j] == 3) leftCount++;
                else break;
            }
            for (int j = i+1; j < n; j++)
            {
                if( givenArray[j] == 1 || givenArray[j] == 3) rightCount++;
                else break;
            }
            sum += leftCount*rightCount;
        }
        int ans = total-sum;
        cout << ans << "\n";
    }
    return 0;
}
 