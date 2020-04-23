#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;

const int Nmax = 200005;
const int INF = 1000000000;
const int MOD = 1000000007;

int a[Nmax], father[Nmax], cnt_sons[Nmax], level[Nmax], cnt_marked[Nmax];
priority_queue<pair<int, int>> Q;
vector<int> edges[Nmax];

void dfs(int node, int fth) {
    father[node] = fth;
    for(int son : edges[node]) {
        if(son == fth) {
            continue;
        }
        cnt_sons[node]++;
        level[son] = level[node] + 1;
        dfs(son, node);
    }
    if(!cnt_sons[node]) {
        Q.push({level[node], node});
    }
}

int main()
{
    int n, k;
    #ifndef ONLINE_JUDGE
        freopen ("data.in","r",stdin);
        freopen ("C.out","w",stdout);
    #endif
    cin.sync_with_stdio( false );
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(0, -1);
    long long ans = 0;
    while(k && !Q.empty()) {
        pair<int, int> node_pair = Q.top();
        int node_father = father[node_pair.second];
        Q.pop();
        ans += node_pair.first;
        k--;
        cnt_marked[node_pair.second]++;
        if(node_father != -1) {
            cnt_sons[node_father]--;
            cnt_marked[node_father] += cnt_marked[node_pair.second];
            if(cnt_sons[node_father] == 0) {
                Q.push({level[node_father] - cnt_marked[node_father], node_father});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}