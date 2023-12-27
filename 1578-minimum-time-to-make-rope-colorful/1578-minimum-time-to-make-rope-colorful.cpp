class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int res = 0, i = 0, j = 0, n = neededTime.size();
        
        while(i < n and j < n)
        {
            int colorMax = 0;
            
            while(j < n and colors[i] == colors[j])
            {
                res+= neededTime[j];
                colorMax = max(colorMax, neededTime[j]);
                j++;
            }
            
            res-= colorMax;
            i = j;
        }
        return res;
    }
};