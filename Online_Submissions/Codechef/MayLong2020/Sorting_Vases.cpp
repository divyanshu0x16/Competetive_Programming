#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
int n, m, k;
int p[20];
int dsu[20];
vector<pair<int, int> > e;
int dp[(1 << 18) + 5];
int nxt[20];
int cnt[20];
bool used[20];
 
int get_anc(int x) {
    if (x == dsu[x]) return x;
    return dsu[x] = get_anc(dsu[x]);
}
 
void dfs(int x) {
    if (used[x]) return;
    used[x] = true;
    if (nxt[x])
        dfs(nxt[x]);
}
 
bool is_simple_cycle(int mask) {
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0;
        used[i] = false;
        nxt[i] = 0;
    }
    for (int i = 0; i < k; ++i)
        if (mask & (1 << i)) {
            int x = e[i].first;
            int y = e[i].second;
            ++cnt[x];
            ++cnt[y];
            nxt[x] = y;
        }
    for (int i = 0; i < n; ++i)
        if (cnt[i] != 0 && cnt[i] != 2) return false;
    for (int i = 0; i < n; ++i) if (cnt[i]) {
        dfs(i);
        break;
    }
    for (int i = 0; i < n; ++i)
        if (cnt[i] && !used[i]) return false;
    return true;
}
 
void solve(int test_id) {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        if (i) scanf(" ");
        scanf("%d", &p[i]);
        --p[i];
    }
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        --x; --y;
        x = get_anc(x);
        y = get_anc(y);
        if (x != y) dsu[x] = y;
    }
    e.clear();
    for (int i = 0; i < n; ++i) {
        int x = i;
        int y = p[i];
        x = get_anc(x);
        y = get_anc(y);
        if (x != y) e.push_back({x, y});
    }
    k = (int)e.size();
    for (int i = 1; i < (1 << k); ++i) {
        if (is_simple_cycle(i)) {
            dp[i] = 1;
        } else dp[i] = 0;
    }
    for (int i = 1; i < (1 << k); ++i) {
        for (int j = i; j > 0; j = (j - 1) & i) {
            if (dp[j] && dp[i ^ j])
                dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
        }
    }
    int result = (int)e.size() - dp[(1 << k) - 1];
    printf("%d\n", result);
}
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tests;
    scanf("%d\n", &tests);
    for (int i = 0; i < tests; ++i) {
        solve(i);
    }
    return 0;
}
 