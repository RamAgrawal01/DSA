#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

string findTimeDifference(string st, string et) {
    int stHours = stoi(st.substr(0, 2));
    int stMinutes = stoi(st.substr(3, 2));
    int stSeconds = stoi(st.substr(6, 2));

    int etHours = stoi(et.substr(0, 2));
    int etMinutes = stoi(et.substr(3, 2));
    int etSeconds = stoi(et.substr(6, 2));

    int finalSeconds = etSeconds - stSeconds;
    int finalMinutes = etMinutes - stMinutes;
    int finalHours = etHours - stHours;

    // Adjust if seconds are negative
    if (finalSeconds < 0) {
        finalSeconds += 60;
        finalMinutes--;
    }

    // Adjust if minutes are negative
    if (finalMinutes < 0) {
        finalMinutes += 60;
        finalHours--;
    }

    // Adjust if hours are negative (crossing midnight)
    if (finalHours < 0) {
        finalHours += 24;
    }

    // Format and return the result
    return (finalHours < 10 ? "0" : "") + to_string(finalHours) + ":" +
           (finalMinutes < 10 ? "0" : "") + to_string(finalMinutes) + ":" +
           (finalSeconds < 10 ? "0" : "") + to_string(finalSeconds);
}

int main(){
    string st , et;
    st = "12:00:00";
    et = "24:00:00";
    cout<<findTimeDifference(st , et);
}