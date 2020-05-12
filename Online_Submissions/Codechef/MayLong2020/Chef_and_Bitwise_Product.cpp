#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
using namespace std;

const long long MX = 1e12;

long long optimal_z;
long long result;
long long x, y, l, r;

long long f(long long x, long long y, long long z) {
	return (x & z) * (y & z);
}

void update_ans(long long z) {
	long long cur = f(x, y, z);
	if (cur > result || (cur == result && z < optimal_z)) {
		optimal_z = z;
		result = cur;
	}
}

void print_binary(long long x) {
	string res = "";
	for (long long i = 42; i >= 0; --i) {
		if (x & (1ll << i))
			res += "1";
		else
			res += "0";
	}
	cout << res << '\n';
}

void solve(int test_id) {
	scanf("%lld %lld %lld %lld\n", &x, &y, &l, &r);
	//assert(l == 0 && r >= 2ll * max(x, y));
	assert(0 <= x && x <= MX);
	assert(0 <= y && y <= MX);
	assert(0 <= l && l <= MX);
	assert(0 <= r && r <= MX);
	assert(l <= r);

	optimal_z = r;
	result = f(x, y, optimal_z);
	update_ans(l);
	bool is_less = false;
	long long bits_or = (x | y);

	for (long long i = 42; i >= 0; --i) {
		long long p = (1ll << i);
		if ((r & p) && (is_less || !(l & p))) {
			long long cur = 0;
			for (long long k = 42; k > i; --k) {
				long long p = (1ll << k);
				if (r & p)
					cur |= p;
			}
			bool is_bigger = is_less;
			for (long long k = i - 1; k >= 0; --k) {
				long long p = (1ll << k);
				if (!(l & p)) {
					if (bits_or & p) {
						cur |= p;
						is_bigger = true;
					}
				} else {
					if (!is_bigger || (bits_or & p))
						cur |= p;
				}
			}
			if (l <= cur && cur <= r)
				update_ans(cur);
			is_less = true;
		}
	}
	printf("%lld\n", optimal_z);
	return;
}

int main(int argc, const char * argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests;
	scanf("%d\n", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i);
	}
	return 0;
}