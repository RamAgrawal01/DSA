#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printSubsequence(string str , string output , int i , vector<string>&ans ){
    //base case 
    if(i>= str.length()){
        ans.push_back(output);
        return;
    }


    //exclude
    printSubsequence(str , output , i+1 , ans);
        //include
    output.push_back(str[i]);
    printSubsequence(str ,output , i+1 , ans );
 
}

int main(){
    string str = "gfg";
    string output = "";
    vector<string> ans ;
    printSubsequence(str , output , 0 , ans);
    cout<<"Printing subsequence: "<<endl;
      // Sort the result in lexicographical order
    sort(ans.begin(), ans.end());
    for(auto val:ans){
        cout<< val<<" ";
    }
    cout<<endl;
    cout<<"Size is: "<<ans.size();
    return 0;
}