/*
Given a list arr of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.
*/

/*
Time: O(2^n)
Space: O(2^n)
Recursion.
At each step we can make a decision to either include the current element or not in the sum
After processing each element in the vector we push our sum to the result
Sort res and return it
*/



#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(vector<int> arr,int N,int i, vector<int>&ans,int sum){
        if(i == N){
            ans.push_back(sum);
            return;
        }
        helper(arr,N,i+1,ans,sum+arr[i]);
        helper(arr,N,i+1,ans,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        helper(arr,N,0,ans,0);
        
        return ans;
    }
};