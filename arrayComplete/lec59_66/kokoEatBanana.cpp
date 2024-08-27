#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the total hours Koko needs to eat all bananas at speed 'k'
int calculateHours(const vector<int>& piles, int k) {
    int totalHours = 0;
    for (int pile : piles) {
        totalHours += (pile + k - 1) / k;  // This is equivalent to ceil(pile / k)
        // (pile + k - 1) / k rounds up the division, which is what ceil would do.
    }
    return totalHours;
}

// Function to find the minimum eating speed 'k' that allows Koko to eat all bananas within 'h' hours
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;  
    int right = *max_element(piles.begin(), piles.end());  
    int ans;
   while(left<=right){
    int mid = left + (right-left)/2;
    int hour = calculateHours(piles , mid);

    if(hour>h){
        left = mid+1;
    }
    else{
        ans = mid;
        right  = mid-1;
    }
   }
    
    return ans;
}

int main() {
    vector<int> piles = {30 , 11 , 23 , 4};
    int h = 6;
    
    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    
    return 0;
}