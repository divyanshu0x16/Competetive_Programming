#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    int t = 7;
    while(t--){
    string size, swap;
    cin >> size >> swap;
    int n = stoi(size);
    int k = stoi(swap);

    vector<string> list(n);
    for (auto &&i : list)
        cin >> i;

    vector<int> array(n, 0);

    for (int i = 0; i < n; i++)
        array[i] = stoi(list[i]);

    bool flag = true;
    for (int i = 0; i < n; i++)
        if ((abs((i + 1) - array[i]))% k == 0)
            continue;
        else
        {
            flag = false;
            break;
        }

    if (flag == false)
        cout << "No"
             << "\n";
    else
        cout << "Yes"
             << "\n";
    }
    return 0;
}
