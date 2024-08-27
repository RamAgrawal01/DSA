#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int findMinDifference(vector<string>&time){
    //step 1 intialize a vector to store minutes:
    vector<int>timeMinutes;
    //step 2 convert HH:MM to minutes integer
    for(int i = 0 ; i<time.size();i++){
        string curr = time[i];
        int hours = stoi(curr.substr(0,2));
        int minitues = stoi((curr.substr(3,2)));
        int totalMin = (hours)*60 + minitues;
        timeMinutes.push_back(totalMin);
    }
    cout<<"Printing array in minutes: ";
    for(int i =0;i<time.size();i++){
        cout<<timeMinutes[i]<<" ";
    }

    //step 3 : sort the array to find minimum differnece of two time
    sort(timeMinutes.begin(),timeMinutes.end());

    //step 4 : find minimum differnce ;
    int mini = INT_MAX;
    for(int i = 1; i<timeMinutes.size() ; i++){
        int minDifference = timeMinutes[i]-timeMinutes[i-1];
        mini = min(mini , minDifference);
    }
    cout<<endl;

    //very important : for differnce of last and first element in the circle
    //eg: 23:59 - 00:00 so once circle is 1440 min

    int lastDifference = (timeMinutes[0]+1440)-timeMinutes[timeMinutes.size()-1];
    mini = min(mini,lastDifference);

    return mini;

}

int main(){
    vector<string>time{"12:10","10:15","13:15","17:20","18:00","19:47","23:59"};

    cout<<"final differnce is: "<<findMinDifference(time);

}