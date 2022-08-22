#include <bits/stdc++.h>
#include <string>

using namespace std;

string repeat(string s, int n)
{
    string s1 = s;
    for (int i=1; i<n;i++)
        s += s1;
    return s;
}

bool vowelSearch(string firstWord){

    vector<string> vowels{"a", "e", "i", "o", "u"};
    for (auto &&i : vowels)
        if( i == firstWord) return true;
    return false;
}

string processSentence(vector<string>& words, vector<string>& vowels){
    string ans = "";
    string oo = "oo";

    int index = 1;
    for(int i = 0; i < words.size(); i++){
        string curr = words[i];
        string firstWord;
        bool vowelCheck = vowelSearch(firstWord.assign(1, curr[0]));

        if( vowelCheck ){
            curr = curr + "moo";
        }else{
            curr = curr.substr(1, curr.length() -1) + curr.front() + "moo";
        }
        curr = curr + repeat("oo", index);
        index++;
        ans += curr + " ";
    }

    return ans;
}

int main(){
    string sentence = "";
    getline(cin, sentence, '\n');
    
    vector<string> vowels{"a", "e", "i", "o", "u"};

    vector<string> words;
    string word = "";

    for(auto i: sentence)
        if( i == ' '){
            words.push_back(word);
            word = "";
        }else{
            word = word + i;
        }
    words.push_back(word);
    
    cout << processSentence(words, vowels) << endl;;
    return 0;
}