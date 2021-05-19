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

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int overlapIntervals(vector<pair < int, int > > &intervals, vector<pair < int ,int > > &allOverlaps)
{
    if (intervals.size() < 2)
        return 0;
    sort(intervals.begin(), intervals.end(), sortbysec);

    int count = 0, last_included = 0;
    for (int i = 1; i < intervals.size(); ++i){
        if (intervals[i].first < intervals[last_included].second)
        { // Overlap
            count++;
            allOverlaps.push_back(intervals[i]);
            if (intervals[i].second < intervals[last_included].second)
                last_included = i;
        }
        else
            last_included = i;
    }
    return count;
}


int32_t main()
{
    fastIO;
    testcase(t)
    {
        int c, n, k;
        cin >> c >> n >> k;
        vector<pair<int, int>> startAndEnd;
        int si, ei;
        for (int i = 0; i < n; i++)
        {
            cin >> si >> ei;
            startAndEnd.push_back(make_pair(si, ei));
        }
        vector<pair < int, int > > allOverlaps;
        int overlapCount = overlapIntervals(startAndEnd, allOverlaps);


        if (k == 0){
            if (overlapCount == 0) cout << "Good" << "\n";
            else cout << "Bad" << "\n";
        }
        else if (k == 1){
            if (overlapCount == 0) cout << "Good" << "\n";
            else if (overlapCount == 1){
                
                pair<int , int > toShift = allOverlaps[0];
                int legnthOfShift = toShift.second-toShift.first+1;

                vector< pair< int, int > > final;

                for (int i = 0; i < n; i++)
                    if (startAndEnd[i] != toShift)
                        final.push_back(startAndEnd[i]);

                bool flag = 0;
                for (int i = 0; i <= final.size()-1; i++){
                            
                    if(i == 0 and (final[i].first-1 >= legnthOfShift)){
                        flag = 1; break; //If i is first element
                    }else if(i == final.size()-1){

                        if( (c-final[i].second >= legnthOfShift) or 
                            final[i].first-final[i-1].second-1 >= legnthOfShift){ 
                                flag = 1; break;
                        }
                    }else{
                        //For all the rest elements
                        if( final[i].first-final[i-1].second-1 >= legnthOfShift){
                            flag = 1; break;
                        }
                    }
                    if(flag == 1) cout << "Good" << "\n";
                    else cout << "Bad" << "\n";
                }
            }
            else cout << "Bad" << "\n";
        }
    }
    return 0;
}
 