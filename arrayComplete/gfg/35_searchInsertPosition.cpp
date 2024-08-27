#include<iostream>
#include<vector>
using namespace std;

int findInsertPosition(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // if the insertion position is at the end

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {  // The condition here should be part of an if block
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;  // Return the answer after the loop ends
}

int main() {
    vector<int> arr{1, 2, 8, 10, 11, 12, 19};
    int target = 14;
    int result = findInsertPosition(arr, target);
    cout << "Result is: " << result;
}
