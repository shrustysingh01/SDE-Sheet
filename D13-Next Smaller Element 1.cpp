/*
Find the next smaller element of all the elements in the given array.
*/

/*
Time: O(n)
Space: O(n)
Stack.

We will see if the top of the stack is greater than equal to the elemnt than it would be popped out.
else res[i] = st.top;

*/
vector<int> nextSmallerElements(vector<int>& nums) {
    vector<int> res(n, -1);
    stack<int> st;
    
    for (int i = nums.size(); i >= 0; --i) {
        while (!st.empty() && st.top() >= nums[i])
            st.pop();
        
        if (!st.empty())
            res[i] = st.top();
        
        st.push(nums[i]);
    }
    
    return res;
}