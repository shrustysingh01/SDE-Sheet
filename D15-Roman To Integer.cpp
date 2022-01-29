
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
* I can be placed before V (5) and X (10) to make 4 and 9. 
* X can be placed before L (50) and C (100) to make 40 and 90. 
* C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

/*
Time: O(n)
Space: O(1)
String.
*/


class Solution {
public:
    map<char,int>mp;
    void num(){
        char arr[7] = {'I','V','X','L','C','D','M'};
        int x = 1;
        for(int i = 0 ; i < 7;i++){
            mp[arr[i]] = x;
            if(i%2 == 0){
                x = x*5;
            }
            else{
                x = x*2;
            }
        }
       
    }
    int romanToInt(string s) {
        num();
        int l = s.length();
        int ans = 0;
        int prev = 0;
        for(int i = l-1; i >= 0; i--){
            int curr = mp[s[i]];
            if(curr>=prev){
                ans = ans+curr;
            }
            else{
                ans = ans-curr;  
            }
            prev = curr;
        }
        return ans;
    }
};