#include <bits/stdc++.h>
using namespace std;

const int mxN=5e4, M=1e9+7;
int n, b[mxN];

void solve() {
	//input
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> b[i];

	//check that b[i] is subset of b[i+1]
	for(int i=0; i+1<n; ++i) {
		if((b[i]&b[i+1])!=b[i]) {
			cout << "0\n";
			return;
		}
	}

	//find x
	int x=0;
	for(int i=0; i<n-1; ++i)
		x+=__builtin_popcount(b[i]);
	//2^x
	int ans=1;
	for(int i=0; i<x; ++i)
		ans=ans*2%M;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}