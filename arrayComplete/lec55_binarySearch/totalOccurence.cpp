#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countOccurrences(vector<int>&arr , int target){
    auto lower = lower_bound(arr.begin(),arr.end(),target);
    auto upper = upper_bound(arr.begin(),arr.end(),target);

    if(lower==arr.end() || *lower != target){
        return 0;
    }
    return upper-lower;
}


int main(){
     int n, target;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in increasing order: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value for searching: ";
    cin >> target;

    int occurrences = countOccurrences(arr, target);

    cout << "Total occurrences of " << target << " is: " << occurrences << endl;

    return 0;
}