#include <bits/stdc++.h>

using namespace std;

int main(){
    string size; cin >> size;
    int n = stoi(size);

    vector<string> tempArray(n);
    for (auto &&i : tempArray)
        cin >> i;

    int k = stoi(tempArray[0]);

    vector<int> array(n-1);
    for (int i = 0; i < n-1; i++)
        array[i] = stoi(tempArray[i+1]);

    vector<int> visited(*max_element(array.begin(), array.end())+1);

    for (int i = 0; i < array.size(); i++)
        visited[array[i]] = 1;
    
    int ans = 0; bool flag = 0;

    for (int i = 0; i <= visited.size(); i++)
    {
        if( visited[i] != 0){
            if(flag) break;
            ans++;
            for(int j =0; j < k; j++) {
                if(i+j > visited.size()-1) {
                    flag = 1;
                    break;
                }
                visited[i+j] = 0;
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}