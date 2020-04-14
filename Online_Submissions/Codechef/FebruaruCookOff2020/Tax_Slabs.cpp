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

int lower_value(vi values, int n){
    int lower_value = 0;
    for (int i = 0; i < values.size() - 1; i++)
    {
        if ( values[i+1] >= n){
            lower_value = values[i];
            break;
        }
    }
    if ( lower_value == 0){
        lower_value = 1500000;
    }
    return lower_value;
}



int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n;
        int total_tax = 0;
        int initial_income = n;
        vi tax_brackets = {250000 , 500000, 750000, 1000000, 1250000, 1500000};
        while ( n > 250000)
        {
            float tax_dedecution;
            if ( n <= 250000 ) {
                tax_dedecution = 0;
            }
            else if ( n > 250000 && n <= 500000 ){
                tax_dedecution = 0.05;
            }
            else if ( n > 500000 && n <= 750000 ){
                tax_dedecution = 0.1;
            }
            else if ( n > 750000 && n <= 1000000 ){
                tax_dedecution = 0.15;
            }
            else if ( n > 1000000 && n <= 1250000 ){
                tax_dedecution = 0.2;
            }
            else if ( n > 1250000 && n <= 1500000 ){
                tax_dedecution = 0.25;
            }
            else if ( n > 1500000 ){
                tax_dedecution = 0.3;
            }

            int lower_bracket = lower_value(tax_brackets, n);

            total_tax += (n - lower_bracket)*tax_dedecution;

            n = lower_bracket;
        }
        cout << initial_income - total_tax << "\n";
    }
    return 0;
}
 