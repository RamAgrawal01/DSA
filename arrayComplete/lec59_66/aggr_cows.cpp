#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlaceCows(vector<int>&stalls , int mid , int k){
    int cows = 1;
    long long lastPosition = stalls[0]; //last placed cow position

    for(int i = 1;i<stalls.size();i++){
        if(stalls[i]-lastPosition>=mid){
            cows++;
            lastPosition = stalls[i];

            if(cows==k){
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls  , int k){
    sort(stalls.begin(),stalls.end());
    long long minInStalls = *min_element(stalls.begin() , stalls.end());
    long long maxInStalls = *max_element(stalls.begin() , stalls.end());
    int low = 1;
    long long high = (maxInStalls-minInStalls);
    int ans ;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(canPlaceCows(stalls , mid , k)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }
    return ans;
}

int main(){
    vector<int>arr{5,4,3,2,1,1000000000};
    int k = 2;
    int ans = aggressiveCows(arr,k);
    cout<<"largest Minimum distance is: "<<ans;
}




//dry run 
// You're correct! If the search space is [1, 8], the first mid value in the binary search would be 4. Let’s do the dry run again with mid = 4.

// Updated Dry Run:
// Input:

// stalls = [1, 2, 4, 8, 9]
// mid = 4
// k = 3 (number of cows)
// Dry Run:
// Initial State:

// cows = 1 (first cow placed at the first stall, index 0)
// lastPosition = 1 (position of the first stall)
// Loop Iteration Details:

// First Iteration (i = 1):

// Current stall: stalls[1] = 2
// Distance from last placed cow: stalls[1] - lastPosition = 2 - 1 = 1
// 1 < 4, so a cow cannot be placed here.
// Continue to the next iteration.
// Second Iteration (i = 2):

// Current stall: stalls[2] = 4
// Distance from last placed cow: stalls[2] - lastPosition = 4 - 1 = 3
// 3 < 4, so a cow cannot be placed here.
// Continue to the next iteration.
// Third Iteration (i = 3):

// Current stall: stalls[3] = 8
// Distance from last placed cow: stalls[3] - lastPosition = 8 - 1 = 7
// 7 >= 4, so place the second cow here.
// cows++ => cows = 2
// Update lastPosition = 8 (the current stall's position)
// Continue to the next iteration.
// Fourth Iteration (i = 4):

// Current stall: stalls[4] = 9
// Distance from last placed cow: stalls[4] - lastPosition = 9 - 8 = 1
// 1 < 4, so a cow cannot be placed here.
// End of loop.