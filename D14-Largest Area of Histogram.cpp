/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/

/*
Time: O(n)
Space: O(n)
Stack.


Keep track of previous smaller element and next smaller element and store their element
as left[i] and right[i]

*/




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);
        int ans = INT_MIN;
        stack<int>st;
        for(int i = 0 ; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                left[i] = 0;
            else
                left[i] = st.top()+1;
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                right[i] = n-1;
            else
                right[i] = st.top()-1;
            
            st.push(i);   
        }
        
        for(int i = 0 ; i < n ; i++){
           cout<<left[i]<<" ";
        }
        cout<<'\n';
        
        for(int i = 0 ; i < n ; i++){
           cout<<right[i]<<" ";
        }
        cout<<'\n';
        
        
        for(int i = 0 ; i < n ; i++){
            int x = (max(left[i],right[i]) - min(left[i],right[i]) +1)*heights[i];
            ans = max(ans,x);
        }
        
        return ans;
    }
};