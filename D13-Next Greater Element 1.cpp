/*
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next 
greater element as described above.
*/

/*
Time: O(n)
Space: O(n)

Stack.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>ans;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
               st.pop();
            }
            if(!st.empty()){
                 mp[nums2[i]] = st.top();
            }else{
                 mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        
        for(int i = 0 ;i< n ; i++){
            cout<<mp[nums2[i]]<<" ";
        }
        cout<<"\n";
        
        for(int i = 0 ; i < nums1.size() ; i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
        
    }
};