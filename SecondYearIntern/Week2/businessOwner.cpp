#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    int t = 1;
    while (t--)
    {
        string size;
        cin >> size;
        int n = stoi(size);

        vector<string> list(n);
        for (auto &&i : list)
            cin >> i;

        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++)
            arr[i] = stoi(list[i]);

        sort(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, (n - i) * arr[i]);

        cout << ans << "\n";
    }
    return 0;
}