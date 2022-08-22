#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/* Solution by divyanshu0x16*/

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int t = 7;
    while(t--){
    string size, employees; cin >> size >> employees;
    int n = stoi(size); int k = stoi(employees);

    map<int, vector<pair<int, int>>> input;
    for (int i = 0; i < n; ++i)
    {
        string arrival, departure, preferred; 
        cin >> arrival >> departure >> preferred;
        int si = stoi(arrival); int fi = stoi(departure); int pi = stoi(preferred);
        input[pi].push_back({si, fi});
    }

    int answer = 0;

    for (auto &&i : input)
    {
        vector<pair<int, int>> current = i.second;
        sort(current.begin(), current.end(), sortbysec);

        int previousTime = -1;
        for (int j = 0; j < current.size(); ++j)
            if (current[j].first >= previousTime)
            {
                answer++;
                previousTime = current[j].second;
            }
    }

    cout << answer << "\n";
    }
    return 0;
}