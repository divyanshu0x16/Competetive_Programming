#include <bits/stdc++.h>
using namespace std;
/* Solution by divyanshu0x16*/
#define int           long long 
#define setbits(x)    __builtin_popcountll(x)
#define zerobits(x)   __builtin_ctzll(x)
#define mod           1000000007 
#define ps(x, y)      fixed<<setprecision(y)<<x
//#define testcase(x)   int x; cin >> x; while(x--)
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

//Code From Geeks For Geeks
int mostFrequent(int array[], int n){
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[array[i]]++;
    }

    int max_freq = 0;
    int res = -1;
    for ( auto i : map)
    {
        if ( max_freq < i.second){
            res = i.first;
            max_freq = i.second;
        }
    }  
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t ; 
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            int array[k];
            for (int j = 0; j < k; j++)
            {
                cin >> array[j];
            }
            cout << mostFrequent(array, k) << " ";
        }
        cout << "\n";
    }
    return 0;
}
 