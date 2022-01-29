
/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
Time: O(n * 2^n)
Space: O(2^n)
Backtracking.
Make res and curr and sort the nums array
Call findSubset with index as 0
Return res
At each call of findSubset
	push the curr into our result
	iterate from idx to nums.size
		if i is not idx and nums i equals nums i - 1 then skip over this element
		push current nums i into curr
		call findsubsets with index as i
		pop out the last element from curr
*/


class Solution {
public:
    void helper(vector<int>& nums,vector<int>v, int i,vector<vector<int>>&ans){
         ans.push_back(v);

       for(int j = i ; j < nums.size() ; j++){
           if(j != i && nums[j] == nums[j-1])
               continue;
           v.push_back(nums[j]);
           helper(nums,v,j+1,ans);
           v.pop_back();
       }
    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
         vector<vector<int>>ans;
          sort(nums.begin(),nums.end());
         helper(nums,v,0,ans);
        return ans;
    }
};