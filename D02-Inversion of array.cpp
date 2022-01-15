#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int Merge(long long arr[], long long s, long long e){
        int i = s;
        int mid = (s+e)/2;
        int j = mid+1;
        vector<long long int>temp;
        long long int count = 0;
        
        while(i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
                count += mid-i+1;
            }
        }
        
        while(i<= mid){
            temp.push_back(arr[i++]);
        }
        
        while(j <= e){
            temp.push_back(arr[j++]);
        }
        
        int k = 0;
        
        for(int i = s ; i <= e ; i++){
            arr[i] = temp[k++];
        }
        
        return count;
        
    }
    
    long long int Inversion(long long arr[], long long s, long long e){
        if( s>= e)
           return 0;
        
        long long int mid = (s+e)/2;
        long long int C1 = Inversion(arr,s,mid);
        long long int C2 = Inversion(arr,mid+1,e);
        long long int CI = Merge(arr,s,e);
        
        return C1+C2+CI;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int s = 0;
        long long int e = N-1;
        return Inversion(arr,s,e);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends