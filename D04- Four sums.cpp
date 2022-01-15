class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j <  n ; j++){
                int sum = nums[i] +  nums[j];
                int front = j+1;
                int back = n-1;
                int target2 = target-sum;
                while(front < back){
                    int twosum = nums[front]+nums[back];
                    if(twosum < target2){
                        front++;
                    }
                    else if(twosum > target2){
                        back--;
                    }
                    else{
                        vector<int>v = {nums[i],nums[j],nums[front],nums[back]};
                        ans.push_back(v);
                        
                       
                        while(front < back && nums[front] == v[2])
                             front++;
                        while( front < back && nums[back] == v[3])
                             back--;
                        
                        v.clear();
                    }
                }
                while( j+1 < n && nums[j+1] == nums[j])
                             j++;
            }
            while( i+1 < n && nums[i+1] == nums[i])
                             i++;
        }
        
        return ans;
        
    }
};