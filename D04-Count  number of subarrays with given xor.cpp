int Solution::solve(vector<int> &A, int B) {
  
    int xorr = 0;
    unordered_map<int,int>mp;

    int c = 0;
    int n = A.size();
    for(int i = 0 ; i < n ; i++){
          xorr = xorr^A[i];
          if(xorr == B){
              c++;
          }
          if(mp.find(xorr^B) != mp.end()){
              c = c+ mp[xorr^B];
          }
          mp[xorr]++;
        }
    return c;

}
