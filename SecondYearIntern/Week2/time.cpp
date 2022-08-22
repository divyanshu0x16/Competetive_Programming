#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int getMinutes( string time ){
    return stoi(time.substr(2, 2));
}

int getHour( string time ){
    return stoi(time.substr(0, 2));
}

int amorpm ( string time ){
    string sub = time.substr(4,2);
    return sub == "AM" ? 1 : 0;
}

bool lessThan( vector<int>& timeOne, vector<int>& timeTwo ){

    if( timeOne[0] == 12 and timeTwo[0] != 12) return true;

    if( timeOne[0] < timeTwo[0] ) return true;
    
    if( timeOne[0] == timeTwo[0] )
        if( timeOne[1] <= timeTwo[1] ) return true;

    return false;
}

bool liesBetween( vector<int>& lInfo, vector<int>& rInfo, vector<int>& currInfo){
    //If L and R both are AM
    if( lInfo[2] & rInfo[2] ){
        //If curr is in PM
        if( !currInfo[2] ) return false;
        else if( lessThan(lInfo, currInfo) and lessThan(currInfo, rInfo)) return true;
    }

    //If L and R both are PM
    if( !lInfo[2] & !rInfo[2] ){
        //If curr is in AM
        if( currInfo[2] ) return false;
        else if( lessThan(lInfo, currInfo) and lessThan(currInfo, rInfo)) return true;
    }

    //If L is in AM and R is in PM
    if( lInfo[2] & !rInfo[2] ){
        //If curr is in AM
        if( currInfo[2] )
            if( lessThan(lInfo, currInfo) ) return true;

        //If curr is in PM
        if( !currInfo[2] )
            if( lessThan(currInfo, rInfo) ) return true;
    }
    return false;
}

int main()
{
    int t = 7;
    while(t--){
    string size, L, R; cin >> size;
    cin >> L >> R;

    vector<string> times(stoi(size));
    for (auto &&i : times)
        cin >> i;
    
    string answer = "";

    int lMinute = getMinutes(L); 
    int lHour = getHour(L);
    int lAM = amorpm(L);
    vector<int> lInfo{ lHour, lMinute, lAM};

    int rMinute = getMinutes(R); 
    int rHour = getHour(R);
    int rAM = amorpm(R);
    vector<int> rInfo{ rHour, rMinute, rAM};

    for (auto &&i : times)
    {
        int currMinute = getMinutes(i);
        int currHour = getHour(i);
        int currAM = amorpm(i);
        vector<int> currInfo{ currHour, currMinute, currAM};

        if(liesBetween(lInfo, rInfo, currInfo)) answer += "1";
        else answer += "0";
    }
    
    cout << answer << "\n";
    }
    return 0;
}

