class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
              
        vector<vector<int>>meetings = intervals;
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>>endTimes;
        endTimes.push(0);
        for(int i= 0; i < meetings.size(); i++)
        {
            int endTime = endTimes.top();
            if(meetings[i][0] < endTime)
               endTimes.push(meetings[i][1]);
            else
            {
                endTimes.pop();
                endTimes.push(meetings[i][1]);
            }            
        }
    return endTimes.size();
    }
};