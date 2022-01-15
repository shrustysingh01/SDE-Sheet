class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++){
            vector<int>v(i+1,1);
            for(int j = 1 ; j < i ; j++){
                  int x = ans[i-1][j-1]+ans[i-1][j];
                  v[j] = x;
              }
             ans.push_back(v);
        }
        return ans;

    }
};