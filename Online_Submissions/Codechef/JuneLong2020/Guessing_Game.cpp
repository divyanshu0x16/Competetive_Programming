#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> ranges, nxt_ranges;
	ranges.push_back({1, n});
	auto size = [&](){
		int len = 0;
		for(auto e : ranges) len += e.second - e.first + 1;
		return len;
	};
	int cnt_q = 0;
	auto query = [&](int x){
		cnt_q++;
		assert(cnt_q <= 100);
		cout << x << endl;
		char ans;
		cin >> ans;
		if(ans == 'E'){
			exit(0);
		}
		return ans;
	};
	auto kth = [&](int k){
		for(auto e : ranges){
			int len = e.second - e.first + 1;
			if(k > len)
				k -= len;
			else
				return e.first + k - 1;
		}
		return -1;
	};
	auto count_small = [&](int x){
		int ans = 0;
		for(auto e : ranges){
			if(e.second <= x){
				ans += e.second - e.first + 1;
			} else {
				if(x >= e.first) ans += x - e.first + 1;
			}
		}
		return ans;
	};
	auto remove = [&](int l, int r){
		nxt_ranges.clear();
		for(auto e : ranges){
			if(e.second < l) nxt_ranges.push_back(e);
			else if(e.first > r) nxt_ranges.push_back(e);
			else {
				if(e.first < l) nxt_ranges.push_back({e.first, l - 1});
				if(e.second > r) nxt_ranges.push_back({r + 1, e.second});
			}
		}
		ranges = nxt_ranges;
	};
	while(true){
		int len = size();
		if (len <= 5){
			for(int i = 1; i <= len; i++){
				query(kth(i));
			}
			break;
		}
		int x = kth(len / 2);
		char last = query(x);
		int L = len / 2 - 1, R = len - len / 2;
		int qr[2] = {x, x};
		bool done = false;
		for(int i = 0; L > 1 && R > 1 && !done;){
			double delta = 0.33;
			if(last == 'G'){
				int np = kth(L * (1 - delta));
				char nxt = query(np);
				if(nxt == last){
					remove(1, np);
					remove(qr[0], qr[1]);
					done = true;
				} else {
					qr[0] = qr[1];
					qr[1] = np;
				}
				last = nxt;
				L = count_small(np - 1);
			} else {
				int np = kth(len - R * (1 - delta));
				char nxt = query(np);
				if(nxt == last){
					remove(np, n);
					remove(qr[1], qr[0]);
					done = true;
				} else {
					qr[0] = qr[1];
					qr[1] = np;
				}
				last = nxt;
				R = len - count_small(np);
			}
			if(!done){
				remove(min(qr[0], qr[1]), max(qr[0], qr[1]));
				len = size();
				L = count_small(min(qr[0], qr[1]));
				R = len - count_small(max(qr[0], qr[1]));
			}
		}
	}
	assert(0);
	return 0;
} 