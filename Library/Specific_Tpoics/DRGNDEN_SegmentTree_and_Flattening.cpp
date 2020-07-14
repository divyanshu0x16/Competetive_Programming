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
#define intpow(a,b)   (int)(pow(a,b) + 0.5)
#define gcd(a,b)      __gcd(a, b)
#define all(x)        (x).begin(), (x).end()
#define ps(x, y)      fixed<<setprecision(y)<<x
#define testcase(x)   int x; cin >> x; while(x--)
#define fastIO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ordered_set   tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define M             (L+R)/2
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

struct SegmentTree{ 
    int n;
    vi a;
    // node<<1 divides the value of the node by 2
    void pull(int node){ a[node] = a[node<<1]+a[(node<<1)+1]; }
    void build(vi& arr, int L, int R, int node){
        if(L==R){
            a[node] = arr[L];
            return;
        }
        build(arr, L, M, node<<1);
        build(arr, M+1, R, (node<<1)+1);
        pull(node);
    }

    void update(int L, int R, int pt, int val, int node){
        if(L==R){
            a[node] = val;
            return;
        }
        if(pt <= M)
            update(L, M, pt, val, node<<1);
        else
            update(M+1, R, pt, val, (node<<1)+1);
        pull(node);
    }
    //Function overloading. 
    //On call, depends on the parameter which is passed which is called.
    void update(int pt, int val){ update(0, n-1, pt, val, 1); }

    int query(int L, int R, int left, int right, int node)
    {
        if(L > R or R < left or L > right)
            return 0;
        if(left <= L && R <= right)
            return a[node];
        else
            return query(L,M,left,right,node<<1)+query(M+1,R,left,right,(node<<1)+1);
    }
    //Function overloading
    int query(int left, int right){ return query(0,n-1,left,right,1); }

    SegmentTree(vector< int >& arr){
        n = arr.size();
        a = vi(4*(arr.size()+1));
        build(arr, 0, n-1, 1);
    }
    SegmentTree(){}
};

struct FlattenedTree{
    int root, n;
    vector<vector<int> > adj;
    vi entr, ext;

    int timer = 0;
    void dfs(int u, int prev)
    {
        entr[u] = timer++;
        for(const int& v : adj[u])
            if( v != prev)
                dfs(v, u);
        ext[u] = timer++;
    }

    SegmentTree segmentTree;
    FlattenedTree(vi& p, vi& s)
    {
        n = p.size();
        adj = vector<vector<int > >(n);

        for (int u = 0; u < n; u++)
            if( p[u] != -1)
            {
                adj[u].push_back(p[u]);
                adj[p[u]].push_back(u);
            }
            else
                root = u;

        entr = vi(n);
        ext = vi(n);

        dfs(root, -1);
 
        vector<int> flattenedTree(2*n);
        for(int u = 0; u < n; u++)
        {
            flattenedTree[entr[u]] = s[u];
            flattenedTree[ext[u]] = -s[u]; 
        }
        segmentTree = SegmentTree(flattenedTree);
    }
    
        void update(int pt, int val)
        {
            segmentTree.update(entr[pt],val);
            segmentTree.update(ext[pt],-val);
        }

        bool is_ancestor(int u, int v) //is u an ancestor of v ?
        {
            return entr[u] <= entr[v] && ext[v] <= ext[u];
        }

        int query(int u, int v)
        {
            if(!is_ancestor(u,v))
                return -1;
            else
                return segmentTree.query(entr[u],entr[v]);
        }
};

int32_t main() {
    fastIO;
    int t=1;
    while(t--){
        // We take the input
        int n, q; cin >> n >> q;
        vi h(n+1, 0), t(n+1, 0);
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        for (int i = 1; i <= n; i++)
            cin >> t[i];

        si travelToRight, travelToLeft;
        vi pRight(n+1), pLeft(n+1);
        pRight[0] = pLeft[0] = -1;

        //We find the optimal previous of every element if both the directions
        auto iterate = [](int i, si& traveled, vi& p, vi& h){
            while (!traveled.empty() and !( h[traveled.top()] > h[i]))
                traveled.pop();
            if(traveled.empty())
                p[i] = 0;
            else
                p[i] = traveled.top();
            traveled.push(i);
        };

        for(int i = 1; i <= n; i++)
            iterate(i, travelToRight, pRight, h);
        for (int i = n; i >= 1; i--)
            iterate(i, travelToLeft, pLeft, h);

        FlattenedTree flat_right(pRight, t), flat_left(pLeft, t);
        while (q--)
        {
            int t, u, v; cin >> t >> u >> v;
            if(t==1)
            {
                flat_left.update(u, v);
                flat_right.update(u, v);
            }
            else
            {
                if( u <= v)
                    cout << flat_right.query(u, v) << "\n";
                else 
                    cout << flat_left.query(u, v) << "\n";
            }
        } 
    }
    return 0;
}
 