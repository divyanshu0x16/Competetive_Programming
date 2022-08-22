#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 7;
    while(t--){
    string input;
    cin >> input;

    map<char, int> freq;
    for (auto &&i : input)
        freq[i]++;

    bool flag = 0;
    map<int, int> freqOfFreq;
    for (auto &&i : freq)
    {
        freqOfFreq[i.second]++;
        if (freqOfFreq[i.second] > 1)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "Yes"
             << "\n";
    else
        cout << "No"
             << "\n";
    }
}