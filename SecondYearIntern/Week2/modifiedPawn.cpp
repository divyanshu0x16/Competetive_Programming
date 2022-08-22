#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    string size;
    cin >> size;
    int n = stoi(size);

    int ans;

    if( n%2 == 0) ans = pow(n, 2)/2;
    else ans = (pow(n, 2) + 1)/2;

    cout << ans << "\n";

    return 0;
}