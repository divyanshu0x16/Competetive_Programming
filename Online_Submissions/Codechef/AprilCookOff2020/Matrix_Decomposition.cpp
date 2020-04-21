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

int fast_exponentiation(int a, int b){
	if ( b==0 ) return 1;
	if ( b%2==0 ){
		int c = fast_exponentiation(a, b/2);
		return (c*c)%mod;
	}
	return (a*fast_exponentiation(a, b-1))%mod;
}

int32_t main() {
	fastIO;
	testcase(t){
		int n, a; 
		cin >> n >> a;
		int num = 1;
		int sum = 0;
		int p = 1;
		for (int i = 0; i < n; i++)
		{
			int pp = fast_exponentiation((a*p)%mod, num);
			num += 2;
			p *= pp;
			p %= mod;
			sum += pp;
			sum %= mod;
		}
		cout << sum << "\n";
	}
	return 0;
}
 