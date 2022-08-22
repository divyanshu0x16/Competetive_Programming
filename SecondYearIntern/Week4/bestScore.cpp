#include <bits/stdc++.h>

using namespace std;

int main(){
    string size; cin >> size;
    int n = stoi(size);

    string problems; cin >> problems;
    int k = stoi(problems);

    map<int, int> scores;
    int pi, si;

    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        string str, word;
        while( str.length() == 0)
            getline(cin, str);
        
        for( auto i: str){
            if ( i == ' ') {
                pi = (stoi(word));
                word = """";
            }
            else word = word + i;
        }
        si = (stoi(word));

        if(scores.find(pi) == scores.end())
            scores[pi] = si;
        else scores[pi] = max(scores[pi], si);  
    }

    int ans = 0;
    for (auto &&i : scores)
        ans += i.second;

    cout << ans << "\n";
    return 0; 
}