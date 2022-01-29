/*
Time: O(lg n)
Space: O(1)
Binary Search.
Do a binary search on only the even indices.
If mid == mid + 1 then we're in left part or else we're in right part
Update the lo/hi pointer correspondingly
*/


int singleNonDuplicate(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (mid % 2 == 1)
            --mid;
        
        if (nums[mid] == nums[mid + 1])
            lo = mid + 2;
        else
            hi = mid;
    }
    
    return nums[lo];
}