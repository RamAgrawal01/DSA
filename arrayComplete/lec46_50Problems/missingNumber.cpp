#include<iostream>
#include<vector>
using namespace std;

int findMissingNumber(vector<int>& arr) {
    int n = arr.size();
    int totalSum = (n * (n + 1)) / 2; 
    int arraySum = 0;

    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }

    return totalSum - arraySum;
}

int main(){
    int n;
    cout<<"Enter number of element: ";
    cin>>n;

   vector<int> arr(n - 1); 

    cout << "Enter elements from 0 to " << n << ", with one missing:" << endl;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

     int missingNumber = findMissingNumber(arr);
    cout << "Missing Number in the array is: " << missingNumber << endl;

    return 0;

    
}