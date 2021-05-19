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

int find_set(int v, vi &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

bool union_sets(int x, int y, vi &parent){
    int a = find_set(x, parent);
    int b = find_set(y, parent);
    if( a == b){
        return false;
    }else{
        parent[a] = b; //If we do parent[b] = a, we get the parent by smallest set, but we can get an isolated element in edge rows
    }
    return true;
}

void unionQuery(vi &parents, vi &size, int x, int y, int &maxi, int m, bool type){

    int next = (type) ? m : 1;
    int setA = find_set(x*m+y, parents);
    int setB = find_set(x*m+y+next, parents);
    if(setA != setB){
        union_sets(setA, setB, parents);
        size[setB] += size[setA];
        maxi = max(maxi, size[setB]);
    }

}

void constructWalls(vvi &matrix, bool vertical, vi &parent, vi &size){
    int rows = matrix.size();
    int column = matrix[0].size();

    int flattened, next = (vertical) ? column : 1;

    int i = 0, j = 0;
    if (vertical == false)
        while (i < rows){ //n-1 becau
            j = 0;
            while (j < column-1){ //m-1 because x+1 gets connected
                if (matrix[i][j] == 0){
                    flattened = i * column + j; // we will update the size of component individually
                    union_sets(flattened, flattened + next, parent);
                }
                j++;
            }
            i++;
        }
    else
        while (i < rows-1){
            j = 0;
            while (j < column){
                if (matrix[i][j] == 0){
                    flattened = i * column + j; // we will update the size of component individually
                    union_sets(flattened, flattened + next, parent);
                }
                j++;
            }
            i++;
        }
}

int32_t main() {
    fastIO;
    testcase(t){
        int n, m, q; cin >> n >> m >> q;
        int totalCells = n*m;

        vector < vector < int > > queries;
  
        vector<vector<int>> matrixForTypeOne( n , vector<int> (m, 0)); 
        vector<vector<int>> matrixForTypeTwo( n , vector<int> (m, 0)); 

        int queryType, x1, y1, x2, y2;
        for (int i = 0; i < q; i++){
            cin >> queryType;

            switch (queryType){
            case 1:
                cin >> x1 >> y1;
                x1--, y1--;
                matrixForTypeOne[x1][y1]++;
                queries.push_back({1, x1, y1});
                break;
            
            case 2:
                cin >> x1 >> y1;
                x1--, y1--;
                matrixForTypeTwo[x1][y1]++;
                queries.push_back({2, x1, y1});
                break;

            case 3:
                cin >> x1 >> y1 >> x2 >> y2;
                x1--, y1--, x2--, y2--;
                queries.push_back({3, x1, y1, x2, y2});
                break;

            case 4:
                queries.push_back({4});
                break;
            }
        }

        //Each cell is marked from 0 to n*m  and initially each array would be its own parent
        vector<int> parent(totalCells), size(totalCells, 0);
        for (int i = 0; i < totalCells; i++)
            parent[i] = i;

        //We will process the queries in reverse, so the sections which do not have a fall get connected first
        constructWalls(matrixForTypeOne, false, parent, size);
        constructWalls(matrixForTypeTwo, true, parent, size);

        //Path Compression
        for (int i = 0; i < totalCells; i++)
            size[find_set(i, parent)]++;
        int maxi = *max_element(all(size));
        
        int answer = 0, setA, setB;
        for (int i = queries.size() - 1; i >= 0; i--)
        {
            if (queries[i][0] == 1)
            {
                int flat = --matrixForTypeOne[queries[i][1]][queries[i][2]];
                if (flat == 0)
                {
                    unionQuery(parent, size, queries[i][1], queries[i][2], maxi, m, false);
                }
            }
            else if (queries[i][0] == 2)
            {
                int flat = --matrixForTypeTwo[queries[i][1]][queries[i][2]];
                if (flat == 0)
                {
                    unionQuery(parent, size, queries[i][1], queries[i][2], maxi, m, true);
                }
            }
            else if (queries[i][0] == 3)
            {
                setA = find_set(queries[i][1] * m + queries[i][2], parent);
                setB = find_set(queries[i][3] * m + queries[i][4], parent);
                if (setA == setB)
                    answer++;
            }
            else
            {
                answer += maxi;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
 