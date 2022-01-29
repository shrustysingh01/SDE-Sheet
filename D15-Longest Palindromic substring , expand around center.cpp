/*
Given a string s, return the longest palindromic substring in s.
*/

/*
Time: O(n * n)
Space: O(1)
String.
*/



class Solution {
public:
    int expandAroundCenter(string str, int l , int r){
        while(l >= 0 && r < str.size() && str[l] == str[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) {
        int start = 0,end = 0;
        int maxlen = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            int l1 = expandAroundCenter(s,i,i);
            int l2 = expandAroundCenter(s,i,i+1);
            
            int len = max(l1,l2);
            
            if(len > maxlen){
                maxlen = len;
                start = i-(len-1)/2; /*remember this*/
                end = i+ len/2;
            }
        }
        
        return s.substr(start,end-start+1);
    }
};