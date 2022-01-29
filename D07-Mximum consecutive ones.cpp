/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

/*
Time: O(n)
Space: O(1)
Two Pointer.
Make two variables, res to store result and curr to find the current number of 1s
Iterate over the array and each time you get a 1 update curr by 1 and mark res as the max of res and curr
If you get a 0 then mark curr as 0
*/



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for(int i = 0 ;i < nums.size() ;i++){
            if(nums[i]  == 1)
                count++;
            else{
                count = 0;
            }
            
            maxi = max(maxi,count);
        }
        
        return maxi;
    }
};