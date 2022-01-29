// Same as D08-1. N meeting in one room

/*
Given N activities with their start and finish day given in vector of pair (start, end). 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
*/

/*
Time: O(n * lg n)
Space; O(n OR lg n) depends on sorting algorithm
Greedy.
Sort the activities according to their first times
Initialise res = 0 to count the result
Initialise lastMeetingEnd = 0 to denote the end time of last meeting (initially 0)
Iterate over all the meetings
    if start of meet is before lastMeetEnd
        include it by updating lastMeetEnd time and incrementing res by 1
Return res
*/

int activitySelection(vector<int> start, vector<int> end, int n) {
    vector<pair<int, int>> acts;
    for (int i = 0; i < n; ++i)
        acts.push_back({ start[i], end[i] });
        
    sort(acts.begin(), acts.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int res = 0, lastActEnd = 0;
    for (auto act : acts) {
        if (act.first > lastActEnd) {
            ++res;
            lastActEnd = act.second;
        }
    }
    
    return res;
}