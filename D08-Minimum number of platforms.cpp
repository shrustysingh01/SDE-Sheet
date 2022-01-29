/*
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. 
Arrival and departure time can never be the same for a train but we can have arrival time 
of one train equal to departure time of the other. At any given instance of time, 
same platform can not be used for both departure of a train and arrival of another train. 
In such cases, we need different platforms.
*/


/*
Time: O(n * lg n)
Space: O(n OR lg n) depends on sorting algorithm
Greedy.


First we will sort both the arrays and set platforms_needed = 1;
then for arrival array we will start iterating from 1 and for departure from 0 
if arrival <= departure then platforms_needed++ and we will increase i+1 else platforms_needed--
and increase j+1;


class Solution {
public:
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int platform_needed = 1;
    	int i = 1;
    	int j = 0;
    	int res = 1;
    	
    	while(i < n && j < n ){
    	    if(arr[i] <= dep[j]){
    	        platform_needed++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	        platform_needed--;
    	        j++;
    	    }
    	    
    	    res = max(res,platform_needed);
    	}
    	
    return res;	
    	
    }
	
};



