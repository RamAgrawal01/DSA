#include<iostream>
#include<vector>
using namespace std;
//without pivot element;
 bool search(vector<int>& arr, int key) {
        
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if the mid is target
        if (arr[mid] == key) {
            return true;
        }
        
        // Handle duplicates on the extremes
        if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
            low++;
            high--;
        }
        
        // If the sorted portion is in the left half
        else if (arr[low] <= arr[mid]) {
            // If target is in the left half
            if (arr[low] <= key && key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // If the sorted portion is in the right half
        else {
            if (arr[mid] < key && key <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr{2,5,6,0,0,1,2};
    int target = 0;
    bool ans = search(arr, target);

    if (ans == true) {
        cout << "Target is present in the array";
    } else {
        cout << "Target is not present";
    }
    
    return 0;
}