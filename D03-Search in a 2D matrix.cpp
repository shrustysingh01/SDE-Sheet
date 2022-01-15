class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int flag = false;
        
        int i = 0, j = c-1;
        int lo = 0, hi = r*c-1;
      
        while(lo <= hi){   
            int mid = lo +(hi-lo)/2;
            if(matrix[mid/c][mid%c] == target)
                return true;
            else if(matrix[mid/c][mid%c] < target)
                lo++;
            else
                hi--;
        }
        
        return flag;
    }
};