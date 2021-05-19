#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           747474747
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
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;

int calc_dist( vi &pointA, vi &pointB){
    int dimension = pointA.size();

    int dist = 0;
    for (int i = 0; i < dimension; i++){
        dist += (pointA[i] - pointB[i])*(pointA[i] - pointB[i]);
    }

    return dist;
}


int32_t main() {
    fastIO;
    testcase(t){
        int n, d; cin >> n >> d;

        vector< vector < int > > points(n, vector< int > (d, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++)
                cin >> points[i][j];
        
        //Initial distances from the tree. Initally every vertec is not in the tree
        vi distances(n, 0); vector<bool> visited(n, false);

        //Add the first vertex to the array
        visited[0] = true;
        for (int i = 1; i < n; i++)
            distances[i] = calc_dist(points[0], points[i]);
        
        int answer = 1; int farthestDist, farthestPoint;

        while(true) //since points are not distinct, we are not sure the number of times the loop will run
        {
            farthestDist = 0;
            for (int i = 0; i < n; i++)
                if ( !visited[i] and farthestDist < distances[i]){
                    farthestDist = distances[i];
                    farthestPoint = i;
                }
            if(farthestDist == 0) break;
            visited[farthestPoint] = true;

            int distance;
            for (int i = 0; i < n; i++)
                if( !visited[i] ){
                    distance = calc_dist(points[farthestPoint], points[i]);
                    distances[i] = max(distance, distances[i]);
                }
            answer = (answer * ( farthestDist%mod ) )%mod;
        }
        cout << answer << "\n";
    }
    return 0;
}
 