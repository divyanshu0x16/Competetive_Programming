#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    int t = 7;
    while(t--){
    string size;
    cin >> size;
    int n = stoi(size);

    vector<string> list(n);
    for (auto &&i : list)
        cin >> i;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
        array[i] = stoi(list[i]);

    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        if (hash.find(array[i]) == hash.end())
            hash[array[i]] = 1;
        else
            hash[array[i]]++;
    }

    int maxFreq = 0;
    for (auto &&i : hash)
        if (maxFreq < i.second)
            maxFreq = i.second;

    int answer;
    if (maxFreq > n / 2)
        answer = maxFreq;
    else
    {
        if (n % 2 == 0)
            answer = n / 2;
        else
            answer = n / 2 + 1;
    }

    cout << answer <<  "\n";
    }

    return 0;
}
