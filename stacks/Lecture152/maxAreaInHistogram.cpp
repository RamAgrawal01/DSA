#include <iostream>
#include <stack>
#include <vector>
#include<limits.h>

using namespace std;

vector<int>prevSmaller(vector<int>&input){
        stack<int> st;
         st.push(-1);

    vector<int> ans(input.size()); 
    

    for (int i = 0; i < input.size(); i++) {
        int curr = input[i];

        while ( st.top()!= -1 && input[st.top()] >= curr) {
            st.pop();
        }

        // Small element found
        ans[i] = st.top();
        // Push
        st.push(i);
}
return ans;
}

vector<int>nextSmaller(vector<int>&input){
        stack<int> st;
         st.push(-1);

    vector<int> ans(input.size()); 
    

    for (int i = input.size() - 1; i >= 0; i--) {
        int curr = input[i];

        while (st.top()!= -1 && input[st.top()] >= curr) {
            st.pop();
        }

        // Small element found
        ans[i] = st.top();
        // Push
        st.push(i);
}
return ans;
}

int findMaxArea(vector<int>& heights){

    int size = heights.size();
    //step 1: prev Smaller output
    vector<int> prev = prevSmaller(heights);
    //step2: next smaller output
    vector<int> next = nextSmaller(heights);
    //step 2: find max Area
    int maxArea = INT_MIN;

    for(int i = 0 ; i<heights.size();i++){

        int lenght = heights[i];

        if(next[i]== -1){
            next[i] =size;
        }

        int width = next[i]- prev[i] -1;

        int area = lenght*width;
        maxArea = max(area , maxArea);
    }
    return maxArea;

}

int main() {
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(6);
    input.push_back(2);
    input.push_back(3);

    int area = findMaxArea(input); 
    cout<<area;


    return 0; // Return statement indicating successful execution
}
