#include <iostream>
#include <vector>
using namespace std;

//method 1 : sort the array and check adjacent values if they are same
//and loops till n-1 because adjacent i and i+1 position are comapre;

//Method 2: negative marking content:array having N+1 element and num belong to range(1,N)
//this help to find indexing by element value
//if indexing is repeating the number is duplicate

//Method 3: set values at same index value if condition take 3 to index 3 then it already duplicate

 

     int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]]) {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

int main() {
    vector<int> arr{3,3,3,3,3};

    int ans = findDuplicate(arr);

    cout << "Duplicate element is: " << ans << endl;

    return 0;
}