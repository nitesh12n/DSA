class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        vector<vector<int>>meetings = intervals;
        sort(meetings.begin(), meetings.end());
        
        for(int i= 1; i < meetings.size(); i++)
        {
            if(meetings[i-1][1] > meetings[i][0])
                return false;
        }
    return true;
        
    }
};