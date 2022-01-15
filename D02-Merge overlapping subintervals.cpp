class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0 , j=1;
        int n =  intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>merged;
        
        for(int j = 0 ; j < n ; j++){
            if(merged.empty()){
                merged.push_back(intervals[j]);
            }
            else if((merged[i][1] < intervals[j][0])){
                 merged.push_back(intervals[j]);
                i++;
            }
             else if(merged[i][1] >= intervals[j][0]){ 
                merged[i][1] = max(merged[i][1],intervals[j][1]);   
            }

        }
        
        return merged;
    }
};