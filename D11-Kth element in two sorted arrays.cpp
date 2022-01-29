
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

/*
Time: O(lg (m + n))
Space: O(1)
Binary Search.


if 1st array contains k is less than the elements of the array then high will be min of n and k 
if second array contains less element than k then lo will be max of 0 or k-m
*/

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m){
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int lo = max(0,k-m), hi = min(n,k);
        
        while(lo <= hi){
            int cut1 = (lo+hi)/2;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ?INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ?INT_MIN : arr2[cut2-1];
            
            int r1 = cut1 == n ?INT_MAX : arr1[cut1];
            int r2 = cut2 == m ?INT_MAX : arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                   return max(l1,l2);
            }
            else if(l1 > r2){
                hi = cut1 -1;
            }
            else{
                lo = cut1 +1;
            }
        }
        
        return 0;
    }
};
