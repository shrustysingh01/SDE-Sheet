class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return;
        bool flag = false;
        int i = n-1;
        int j = n-1;
        while(i > 0){
            if(nums[i-1] < nums[i]){
                flag = true;
                while(nums[j] <= nums[i-1]){  
                    j--;    
                }
               swap(nums[i-1],nums[j]);
                break;
            }
            i--;
        }
        
        reverse(nums.begin()+i,nums.end());
        if(flag == false){
            sort(nums.begin(),nums.end());
        }
        return;
    }
};