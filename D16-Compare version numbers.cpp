class Solution {
public:
    vector<int> Number(string s){
        int Size = s.size();
        vector<int>res;
        string temp = "";
        for(int i = 0 ; i < Size ; i++){
            if(s[i] != '.'){
                temp += s[i];
            }
            else{
                res.push_back(stoi(temp));
                temp = "";
            }
        }
        
        if(temp != "")
            res.push_back(stoi(temp));
        
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1 = Number(version1);
        vector<int>v2 = Number(version2);
        
        for (auto x : v1)
        cout << x << ' ';
            cout << '\n';
    
        for (auto x : v2)
        cout << x << ' ';
            cout << '\n';
        cout<<stoi("0");
        
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] == v2[j]){
                i++;
                j++;
            }
            else if(v1[i] > v2[j]){
                return 1;
            }
            else{
                return -1;
            }      
        }
        
        while(i < v1.size()){
            if(v1[i] > 0){
                return 1;   
            }
            i++;
        }
        
        while(j < v2.size()){
            if(v2[j] > 0){
                return -1;
            }
             j++; 
        }
        return 0;
    }
};