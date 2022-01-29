/*Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/


/*
Time: O(2^t * k), where t = target, k = average length
Space: O(k * x), where k = average length, x = combinations
*/

class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, vector<vector<int>>& ans , vector<int>&ds){
       
        if( i == candidates.size()){
            if(target == 0)
                ans.push_back(ds);
            return;        
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            helper(candidates,target-candidates[i],i,ans,ds);
            ds.pop_back();
        }
        helper(candidates,target,i+1,ans,ds);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n = candidates.size();
        vector<int>ds;
        helper(candidates,target,0,ans,ds);
        
        return ans;
    }
};

