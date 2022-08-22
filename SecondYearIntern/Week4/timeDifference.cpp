#include <bits/stdc++.h>

using namespace std;

int getHour(string time){
    int hour = stoi(time.substr(0, 2));
    string am = time.substr(8, 2);
    bool PM = ( time.substr(8, 2) == "AM") ? 0 : 1;
    if(PM) hour += 12;
    return hour;
}

string toString(int num){
    string ans;
    if( num < 10 ){
        ans = "0"+to_string(num);
    }else{
        ans = to_string(num);
    }
    return ans;
}

int getMinute(string time){
    return stoi(time.substr(3, 2));
}

int getSecond(string time){
    return stoi(time.substr(6, 2));
}

int main() {

    string startTime; cin >> startTime;
    string endTime; cin >> endTime;

    int startHour = getHour(startTime);
    int endHour = getHour(endTime);

    int startMinute = getMinute(startTime);
    int endMinute = getMinute(endTime);

    int startSecond = getSecond(startTime);
    int endSecond = getSecond(endTime);

    int secondDiff = endSecond + (60-startSecond);
    int minuteDiff = endMinute + (59-startMinute);
    int hourDiff = endHour - startHour - 1;

    if( secondDiff >= 60){
        minuteDiff++;
        secondDiff = secondDiff - 60;
    }

    if( minuteDiff >= 60){
        hourDiff++;
        minuteDiff = minuteDiff - 60;
    }

    string ans = toString(hourDiff) + ":" + toString(minuteDiff) + ":" + toString(secondDiff); 
    cout << ans << "\n";

    return 0;
}