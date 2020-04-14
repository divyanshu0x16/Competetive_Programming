#include <bits/stdc++.h>
using namespace std;

void solve() {
	//input
	int n, q, c[2]={};
	cin >> n >> q;
	for(int i=0, a; i<n; ++i) {
		cin >> a;
		//add a to frequency array based on parity
		++c[__builtin_popcount(a)%2];
	}

	//queries
	for(int p; q--; ) {
		cin >> p;
		//determine the parity of p
		int z=__builtin_popcount(p)%2;
		//z is the 0s and z^1 (which flips z) is the 1s
		cout << c[z] << " " << c[z^1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}