#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string x , string y){
    return x+y > y+x;
}

string largestNumber(vector<int>num){
    
    vector<string>numstr;
    for(int number : num){
        numstr.push_back(to_string(number));
    }

    //sort
    sort(numstr.begin() , numstr.end() , compare);

    //concenate
    string largestNum;
    for(string numStr : numstr){
        largestNum = largestNum + numStr;
    }

    //handle the edge case where the result is all zxeroes
    if(largestNum[0]=='0'){
        return "0";
    }

    return largestNum;
}


int main(){
    vector<int>arr{3,30,34,5,9};
    string ans = largestNumber(arr);
    cout<<ans;
}