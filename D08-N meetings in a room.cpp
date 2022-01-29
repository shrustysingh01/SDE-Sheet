/*
There is one meeting room in a firm. There are N meetings in the form of 
pair i(start, end) where start is start time of meeting i and end is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting 
can be held in the meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

/*
Time: O(n * lg n)
Space: O(n OR lg n) depends on sorting algorithm
Greedy.


we will sort the array using the ending time if ending time is same then by their starting time
set the limit to end of first elemnt , and res = 1, including that first element.
now we will check if start time of another one is greater then limit , if yes ,
increment the res and set limit to ending time of that array.
*/


class Solution {
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int end;
        int start;
        int pos;
    };
    struct compare{
        bool operator()(struct meeting m1, struct meeting m2){
            if(m1.end == m2.end){
                m1.pos < m2.pos;
            }
            return m1.end < m2.end;
        }
    };
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        struct meeting meet[n];
        for(int i = 0 ; i < n ; i++){
           meet[i].end = end[i];
           meet[i].start = start[i];
           meet[i].pos = i+1;
        }
        
        sort(meet, meet+n ,compare());
        
        vector<int>ans;
        
        int limit = meet[0].end;
        int res = 1;
        
        for(int i = 1 ; i < n ; i++){
            if(meet[i].start > limit){
                res++;
                limit = meet[i].end;
            }
        }
        
        return res;
    }
};