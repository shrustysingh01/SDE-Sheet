class Solution {
public:
    int rec(int x, int y , int m , int n,vector<vector<int>> &dp){
        if(x == m || y == n){
            return 0;
        }
        if((x == m-1) && (y == n-1)){
            return 1;
        }
        if(dp[x][y] != -1)
            return dp[x][y];
        else return dp[x][y] = rec(x+1,y,m,n,dp)+rec(x,y+1,m,n,dp);
    }
    
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int R = m-1;
        double ans = 1.0;
        
        for(int i = 1; i <= R ; i++){
            ans = ans *(N-i+1)/i;
        }
        return round(ans);
    }
};