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
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

int findParent(int v, vi &parent){
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void unionSet(int x, int y, vi &size, vi &parent){
    if( size[x] < size[y] )
        swap(x, y);
    parent[y] = x;
    size[x] += size[y];
}

int32_t main() {
    fastIO;
    testcase(t){
        int n; cin >> n;

        vector< vector < int > > points(n, vector< int > (n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> points[i][j];

        //We need to find MST of all the n points. Due to loyalty, M[i][j] == M[j][i]
        // i.e., M is a symmetric matrix
        vector< pair < int, pair < int, int> > > friends;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if( i < j and points[i][j]) friends.push_back( make_pair(points[i][j], make_pair(i, j))); 

        //To find MST we will apply Kurskal's algorithm
        //Base set-up
        sort(all(friends));
        int length = friends.size();
        vi parent(n), size(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;


        int weight, counter = 0, ans = 0; pii currPair; 

        for (int i = 0; i < length; i++)
        {
            weight = friends[i].first;
            currPair = friends[i].second;

            int parentA = findParent(currPair.first, parent);
            int parentB = findParent(currPair.second, parent);

            if( parentA != parentB){
                unionSet(parentA, parentB, size, parent);
                counter++;
                ans += weight;
            }
        }
        if( n==1) 
            if ( points[0][0] == 0) cout << -1 << "\n";
            else {
                ans = points[0][0];
                cout << ans << "\n";
            }
        else if( counter == n-1) cout << ans*2 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
 