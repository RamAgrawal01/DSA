#include<iostream>
#include<vector>
using namespace std;

bool sorted(vector<int>& arr, int index){
    if(index ==  arr.size() - 1){
        return true;
    }
    return (arr[index] < arr[index + 1] && sorted(arr, index + 1));

};

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 6};
    
    bool ans = sorted(arr, 0);
    cout << (ans ? "Sorted" : "Not Sorted") << endl;  
    
    return 0;
}