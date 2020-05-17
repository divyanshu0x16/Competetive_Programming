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


int32_t main() {
	fastIO;
	int w = 1;
	testcase(t){
		int n, k; cin >> n >> k;
		int given[n]; vi k_indices;
		for (int i = 0; i < n; i++)
		{
			cin >> given[i];
			if ( given[i] == k)
				k_indices.push_back(i);
		}
		int ans = 0;
		for (auto &&i : k_indices)
		{
			bool flag = 1;
			for (int j = 0; j < k; j++)
			{
				if ( given[i+j] == (k-j))
					continue;
				else{
					flag = 0;
					break;
				}
			}
			if ( flag == 1)
				ans++;
		}
		cout << "Case #" << w << ": " <<ans << "\n";
		w++;	
	}
	return 0;
}
 