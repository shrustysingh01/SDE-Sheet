class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char,int>mp;
        
        int i = 0;
        while(i < s.size()){
            mp[s[i]]++;
            mp[t[i]]--;
            i++;
        }
        
        for(auto x : mp){
            if(x.second > 0)
                return false;
        }
        
        return true;
    }
};