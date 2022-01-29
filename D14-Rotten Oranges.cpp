/*
You are given an m x n grid where each cell can have one of three values:
* 0 representing an empty cell,
* 1 representing a fresh orange, or
* 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

/*
Time: O(n * n)
Space: O(1)
BFS.
*/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0;
        int count = 0;
        int day = 0;
        queue<pair<int,int>>q;
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0)
                    tot++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            int k = q.size();
            count += k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)                                continue;
                    //if(grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    
                }
                
            }
            if(!q.empty())
                day++;
        }
        
        if(count == tot)
            return day;
        
        return -1;
    }
};