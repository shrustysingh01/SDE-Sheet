/*
Time: O(n)
Space: O(1)
Four Pointer.
Make two pointer which point to the left and right ends and two pointer which stores the maximum found from the ends
While l < r:
	if height of l is less than height of r:
		if lmax > l heigh, add the difference to res
		else, update lmax
		increment l
	else
		if rmax > r heigh, add the difference to res
		else, update rmax
		decrement r
Return res */

class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();

       if(n==0)
           return 0;
        
        int maxleft = height[0];
        int maxright = height[n-1];
        int count = 0;
        
        int res = 0;
        int left = 1;
        int right = n-2;
        
        while(left <= right){
            if(maxleft <= maxright){
                maxleft = max(height[left],maxleft);
                res += maxleft-height[left];
                left++;
                    
            }
            else{
                maxright = max(height[right],maxright);
                res += maxright-height[right];
                right--;
            }
        }
        return res;
        
    }
};