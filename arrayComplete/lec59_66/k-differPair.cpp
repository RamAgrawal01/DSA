#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

int findK_differ(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int i = 0;
    int j = 1;

    while (j < nums.size()) {
        int diff = nums[j] - nums[i];

        if (diff == k) {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff > k) {
            i++;
        }
        else {
            j++;
        }

        if (i == j) {
            j++;
        }
    }
    return ans.size();
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    int k = 1;
    int ans = findK_differ(nums, k);
    cout << "Total pair count is: " << ans;
}
