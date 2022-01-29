/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

/*
Time: O(n)
Space: O(n)
String.

*/





class Solution {
public:
    string reverseWords(string s) {
        string x;
        string ans = "";
        int len = 0,prev = 0;
        vector<string>words;
        
    
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                x = s.substr(prev , len);
                if(x.size() > 0)
                    words.push_back(x);
                
                prev = i+1;
                len = 0;
            }
            else{
                len++;
            }
        }
        x = s.substr(prev , len);
        if(x.size() > 0)
            words.push_back(x);
        
        ans = words.back();
        
        for(int i = words.size()-2 ; i >= 0 ; i--){
            ans += ' '+ words[i];
        }
        
        return ans;
    }
};