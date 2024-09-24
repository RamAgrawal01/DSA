#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int>&candidates , int target , int start , vector<int>&current , vector<vector<int>>& result ){
    if(target==0){
        //found a valid combination
        result.push_back(current);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=start;i<candidates.size();i++){
        current.push_back(candidates[i]);
        //recursion with reduced target and same starting index
          backtrack(candidates, target - candidates[i], i, current, result);
        //backtrack remove the last element due to vector
        current.pop_back();
    }


}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;
}

int main() {
    vector<int> candidates = {2};
    int target = 1;
    
    vector<vector<int>> combinations = combinationSum(candidates, target);

    cout << "Unique combinations are:" << endl;
    for (const auto& combination : combinations) {
        cout << "{ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}