#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, q, a[mxN], ans[mxN], ql[mxN], qr[mxN], qy[mxN], ft[mxN];

void upd(int i, int x) {
	for(++i; i<n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for(; i; i-=i&-i) // increments the lowest set-bit of i For eg:- i = 5 = 0101. i%-i = 0001
		r+=ft[i];
	return r;
}

struct event {
	int y, t, i;
	bool operator<(const event &o) const {
		return make_pair(y, t)<make_pair(o.y, o.t);
	}
};

void solve() {
	//input
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<q; ++i)
		cin >> ql[i] >> qr[i] >> qy[i], --ql[i], --qr[i];

	vector<event> ve;
	//create events for the segments
	for(int i=0; i+1<n; ++i) {
		//add segment
		ve.push_back({min(a[i], a[i+1]), 1, i});
		//remove segment
		ve.push_back({max(a[i], a[i+1]), 3, i});
	}
	//create events for the queries
	for(int i=0; i<q; ++i)
		ve.push_back({qy[i], 2, i});

	//process events
	sort(ve.begin(), ve.end());
	for(event e : ve) {
		if(e.t==1) {
			//add segment
			upd(e.i, 1);
		} else if(e.t==2) {
			//answer query
			ans[e.i]=qry(qr[e.i])-qry(ql[e.i]);
		} else {
			//remove segment
			upd(e.i, -1);
		}
	}

	//output
	for(int i=0; i<q; ++i)
		cout << ans[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}