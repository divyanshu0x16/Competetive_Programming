#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

class Solution {

public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }

    long double slope(long double x1, long double y1, long double x2, long double y2){
        return (y2 - y1) / (x2 - x1);
    }
    
    bool compareFloatNum(long double a, long double b)
    {
        if (abs(a - b) < 1e-30) {
            return 0;
        }
        else {
            return 1;
        }
    }
 
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), sortcol);

        if(stockPrices.size() == 1){
            return 0;
        }

        int ans = 1;
        long double prevSlope = slope( stockPrices[0][0], stockPrices[0][1], stockPrices[1][0], stockPrices[1][1]);

        for (int i = 1; i < stockPrices.size()-1; i++)
        {
            long double currSlope = slope( stockPrices[i][0], stockPrices[i][1], stockPrices[i+1][0], stockPrices[i+1][1]);
            if( compareFloatNum(currSlope, prevSlope) ){
                ans += 1;
                prevSlope = currSlope;
            }
        }
        
        return ans;
    }
};

int32_t main() {
    Solution s;
    vector<vector<int> > stockPrices = {{1,1},{499999999,2},{999999998,3},{1000000000,5}};
    std::cout << s.minimumLines(stockPrices) << "\n";
    return 0;
}
 