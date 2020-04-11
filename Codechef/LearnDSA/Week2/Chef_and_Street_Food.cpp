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
		int n; cin >> n;
		int max_profit = 0;
		for (int i = 0; i < n; i++)
		{
			int Si, Pi, Vi;
			cin >> Si >> Pi >> Vi;
			int current_profit;
			if ( Pi%Si == 0){
				current_profit = (Pi/(Si+1))*Vi;
			}else{
				current_profit = floor(Pi/(Si+1))*Vi;
			}
			if ( current_profit > max_profit){
				max_profit = current_profit;
			}
		}
		cout << max_profit << "\n";
	}
	return 0;
}
 