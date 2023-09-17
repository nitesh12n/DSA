class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
               
        int maxLen = 0;
        int maxLenCount = 1;
        
        for(auto it : rectangles)
        {
            int k = min(it[0], it[1]);
            
            if(k > maxLen)
            {
                maxLen = k;
                maxLenCount = 1;
            }
            else if (k == maxLen)
                maxLenCount++;
        }
    return maxLenCount;
    }
};