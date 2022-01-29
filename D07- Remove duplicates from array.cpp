/*Make a slow pointer i = 0 and a fast pointer j
Iterate j pointer from 1 to end of nums vector
    if nums at i equals nums at j then continue
    else increment i and assign nums at i to be equal to nums at j (since we have already processed i before it doesn't matter
        if we change the value at slow pointer location)
Return i + 1
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j =0, n = nums.size();
        if(n == 0 || n == 1)
            return n;
        for(int i = 1 ; i  < n ; i++){
               if(nums[i] == nums[j])
                   continue;
                   
                 nums[++j] = nums[i];

        }
        
         return j+1;
    }
};