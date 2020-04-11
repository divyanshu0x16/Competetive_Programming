#include <bits/stdc++.h>

using namespace std;

#define int int64_t

bool lose(int A, int X, int B, int Y, int Z) {
	int t1 = (Z - A + X - 1) / X;
	int t2 = (Z - B + Y - 1) / Y;
	return t1 >= t2;
}

void solve() {
	int N, A, B, X, Y, Z;
	cin >> N >> A >> B >> X >> Y >> Z;
	priority_queue<int> C;
	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		C.push(t);
	}
	int ans = 0;
	while(C.top() != 0 && lose(A, X, B, Y, Z)) {
		ans++;
		A += C.top();
		C.push(C.top() / 2);
		C.pop();
	}
	if(lose(A, X, B, Y, Z)) {
		cout << "RIP" << endl;
	} else {
		cout << ans << endl;
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}