class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>last(256,-1);
        int len = 0;
        int start = 0;
        map<char,int>mp;
        for(int end = 0 ; end < s.length() ; end++){
             if(mp.find(s[end]) != mp.end()){
                 start = max(start, mp[s[end]]+1);
             }
            len = max(len , end - start +1);
             mp[s[end]] = end;
            
        }
        
        return len;
    }
};