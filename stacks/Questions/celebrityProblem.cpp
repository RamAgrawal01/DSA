#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int celebrity(vector<vector<int> >& mat) {
        
        stack<int> st;

        //step1: push all the element in the stack
        for(int i =0 ; i<mat.size();i++){
            st.push(i);
        }

        //step2: Run discard method to get might be celebrity
        while(st.size()!=1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            //if A knows N
            if(mat[a][b]){
                //discard a because not celebrity
                st.push(b);
            }
            else{
                //discard b because b not celebrity
                st.push(a);
            }
         }

         //step3: last element verify for celebrity
         int mightBeCelebrity=st.top();
         st.pop();

         //show not known anyone
         for(int i=0;i<mat.size();i++){
            if(mat[mightBeCelebrity][i]!=0){
                return -1;
            }
         }
         //check everyone known celebrity
         for(int i=0;i<mat.size();i++){
            if(mat[i][mightBeCelebrity]==0 && i != mightBeCelebrity){
                return -1;
            }
         }
         //is the celebrity
         return mightBeCelebrity;
    }
};



int main() {
    vector<vector<int> > M = {{0, 1, 0},
                              {0, 0, 0},
                              {0, 1, 0}};
    Solution ob;
    cout << "The celebrity is " << ob.celebrity(M) << endl;
    return 0;
}