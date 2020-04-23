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
		int n, p; cin >> n >> p;
		n = min(n, p);
		vector < int > a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] %= p;
		}
		vector < int > parent(p, -1), newParent(p, -1);
		for (int t = 0; t < n && parent[0] == -1; t++)
		{
			int v = a[t];
			copy(all(parent), newParent.begin());
			if(newParent[v] == -1){
				newParent[v] = t;
			}
			for (int i = 0; i < p; i++)
			{
				if (parent[i] != -1 && parent[(i+v)%p] == -1)
				{
					newParent[(i+v)%p] = t;
				}	
			}
			copy(all(newParent), parent.begin());
		}
		if( parent[0] == -1){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}
 