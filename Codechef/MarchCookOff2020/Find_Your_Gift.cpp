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
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;


int32_t main() {
    fastIO;
    testcase(t){
        int n;
        cin >> n;
        string str;
        cin >> str;
        char previous_char = 'A';
        pii ans;
        ans.first = 0;
        ans.second = 0;
        for (int i = 0; i < n; i++)
        {
            if ( previous_char == 'A'){
                previous_char = str[0];
            }

            if ( (str[i] == 'L' || str[i] == 'R') && i >= 1){
                if ( previous_char == 'L' || previous_char == 'R') continue;
            }

            if ( (str[i] == 'U' || str[i] == 'D') && i >= 1){
                if ( previous_char == 'U' || previous_char == 'D') continue;
            }

            if  ( str[i] == 'L') ans.first--;
            else if ( str[i] == 'R') ans.first++;
            else if ( str[i] == 'U') ans.second++;
            else if ( str[i] == 'D') ans.second--;

            previous_char = str[i];
        }
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
 