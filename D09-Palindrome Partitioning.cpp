/*
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.
*/

/*
Time: O(n * 2^n)
Space: O(n)
Backtracking.
*/

void findPartition(int idx, vector<string>& curr, vector<vector<string>>& res, string s) {
    if (idx >= s.size()) {
        res.push_back(curr);
        return;
    }
    
    for (int i = idx; i < s.size(); ++i) {
        if (isPalindrome(s, idx, i)) {
            curr.push_back(s.substr(idx, i - idx + 1));
            findPartition(i + 1, curr, res, s);
            curr.pop_back();
        }
    }
    
    return;
}

bool isPalindrome(string s, int start, int end) {
    string str = s.substr(start, end - start + 1);
    
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    return str == rev;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> curr;
    
    findPartition(0, curr, res, s);
    
    return res;
}