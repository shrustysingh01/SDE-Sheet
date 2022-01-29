
/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/

/*
Time: O(2^n)
Space: O(n)
Backtracking.
*/

class Solution {
public:
    void helper(vector<int>& arr, int ind ,int target,vector<int>& ds, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind ; i < arr.size() ; i++){
            if(i != ind && arr[i]== arr[i-1]) continue;
            if(arr[i] <= target){
            ds.push_back(arr[i]);
            helper(arr,i+1,target-arr[i],ds,ans);
            ds.pop_back(); 
            }
        }   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
         vector<int>ds;
        helper(candidates,0,target,ds,ans);
        return ans;
    }
};