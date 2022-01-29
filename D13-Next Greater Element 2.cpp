/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/

/*
Time: O(n)
Space: O(n)
Stack.

we will start from 2*n-1 as a imaginary array,
and look for nums[i%n]
and push that as st.push(nums[i%n]) in stack as well.

*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,-1);
        stack<int>st;
        for(int i = 2*n -1 ; i >= 0 ; i --){
            
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            if(i < n && !st.empty()){
                res[i] = st.top();
            }
            
            st.push(nums[i%n]);
        }
        
        return res;
    }
};