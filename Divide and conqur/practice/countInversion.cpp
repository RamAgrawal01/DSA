#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    long long mergeAndCount(vector<long long>& arr, int left, int mid, int right) {
        vector<long long> leftSub(arr.begin() + left, arr.begin() + mid + 1);
        vector<long long> rightSub(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;
        long long inversions = 0;

        while (i < leftSub.size() && j < rightSub.size()) {
            if (leftSub[i] <= rightSub[j]) {
                arr[k++] = leftSub[i++];
            } else {
                arr[k++] = rightSub[j++];
                inversions += leftSub.size() - i; // All remaining elements in leftSub are greater than rightSub[j]
            }
        }

        while (i < leftSub.size()) {
            arr[k++] = leftSub[i++];
        }

        while (j < rightSub.size()) {
            arr[k++] = rightSub[j++];
        }

        return inversions;
    }

    long long mergeSortAndCount(vector<long long>& arr, int left, int right) {
        long long inversions = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inversions += mergeSortAndCount(arr, left, mid);
            inversions += mergeSortAndCount(arr, mid + 1, right);
            inversions += mergeAndCount(arr, left, mid, right);
        }
        return inversions;
    }

public:
    long long int inversionCount(vector<long long>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<long long> arr = {8, 4, 2, 1};
    Solution solution;
    cout << "Number of inversions: " << solution.inversionCount(arr) << endl;
    return 0;
}
