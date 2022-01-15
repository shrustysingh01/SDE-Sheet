class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1;
        int cnt1 = 0 , cnt2 = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(num1 == nums[i]){
                cnt1++;
            }
            else if(num2 == nums[i]){
                cnt2++;
            }
            else if(cnt1 == 0){
                num1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0){
                num2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
           // cout<<num1<<" "<<num2<<'\n';
        }
        //cout<<num1<<" "<<num2<<'\n';
        vector<int>ans;
        int c1 = 0, c2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1){
                c1++;
            }
            else if(nums[i] == num2){
                c2++;
            }
        }
        
        if(c1 > n/3){
            ans.push_back(num1);
        }
         if(c2 > n/3){
            ans.push_back(num2);
        }
       return ans; 
    }
};