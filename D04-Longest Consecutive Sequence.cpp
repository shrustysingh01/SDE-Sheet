class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int len = 0;
        int n = nums.size();
        for(int i = 0 ;i < n ; i++){
            s.insert(nums[i]);
        }
        
        for(int i = 0 ; i < n; i++){
            int count = 0;
            if(s.find(nums[i]-1) == s.end()){
                int x = nums[i];
                while(s.find(x)!= s.end()){
                    count++;
                    x++;
                }
               len = max(len , count); 
            }
        } 
        return len;   
    }
};