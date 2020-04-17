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


int32_t main() {
	fastIO;
	int t = 1;
	while(t--){
		int n; cin >> n;
		//First Line
		cout << '*' ;
		for (int i = 0; i < ((n/2))-1; i++){
			cout << " ";
		}
		for (int i = 0; i < ((n/2)+1); i++){
			cout << '*';
		}
		cout << "\n";
		// Till middle line
		for (int i = 0; i < ((n/2)-1); i++){
			cout << '*';
			for (int j = 0; j < ((n/2)-1); j++)
			{
				cout << " ";
			}
			cout << '*' << "\n";
		}
		// Middle line
		for (int i = 0; i < n; i++){
			cout << '*' ;
		}
		cout << "\n";
		//After middle line
		for (int i = 0; i < ((n/2)-1); i++){
			for (int i = 0; i < n/2; i++){
				cout << " ";
			}
			cout << '*';
			for (int i = 0; i < ((n/2)-1); i++){
				cout << " ";
			}
			cout << '*' << "\n";
		}
		// Last line
		for (int i = 0; i < ((n/2)+1); i++)
		{
			cout << '*';
		}
		for (int i = 0; i < ((n/2)-1); i++)
		{
			cout << " ";
		}
		cout << '*' << "\n";		
	}
	return 0;
}
 