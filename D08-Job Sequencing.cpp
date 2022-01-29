/*
Given a set of N jobs where each jobi has a deadline and profit associated with it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit if and only if the job is completed by its deadline. 
The task is to find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
*/

/*
Time: O(n * n)
Space: O(n)
Greedy.
Sort the given job array on decreasing profits
Find the total available time by iterating over all the jobs and finding the one with max dead time
Create jobSet vector with -1 all
Now iterate over all the job
    iterate over all the possible times from job.dead time to 1
        if jobSet is not set then 
            set it as current job's id and increment jobCount by 1 and increment jobProfit by job's profit
            break out
Return jobCount and jobProfit
*/



class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int count = 0;
        sort(arr,arr+n,[&](Job& a,Job& b){
            return a.profit > b.profit;
        });
        
        int maxi = 0, pr = 0;
        for(int i = 0 ;i < n ; i++){
            maxi = max(maxi,arr[i].dead);
        }
        
        vector<int>ans(maxi+1,-1);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = arr[i].dead ; j > 0 ; j--){
                if(ans[j] == -1){
                    ans[j] = i;
                    pr +=arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        
        return {count,pr};
    }
};