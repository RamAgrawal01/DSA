#include<iostream>
#include<vector>
using namespace std;

vector<int> findK_closest(vector<int>& arr, int k, int x) {
    int left = 0;
       int right = arr.size()-1;
       
       while((right-left)>=k){
           
           if(x-arr[left]>arr[right]-x){
               left++;
           }
           else{
               right--;
           }
       }
       vector<int>result;
       for(int i=left ; i<=right ; i++){
           result.push_back(arr[i]);
       }
       return result;
}

int main() {
    vector<int> arr{12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;
    vector<int> ans = findK_closest(arr, k, x);

    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}