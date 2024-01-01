class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0, size = height.size();
        vector<int>leftMax(size), rightMax(size);
        
        leftMax[0] = height[0];
        rightMax[size - 1] = height[size - 1];
                           
        for(int i = 1; i < size; i++)
              leftMax[i] = max(leftMax[i - 1], height[i]);  
         for(int i = size - 2; i >= 0; i--)
              rightMax[i] = max(rightMax[i + 1], height[i]);    
                
        for(int i = 1; i < size - 1; i++)
            res+= min(leftMax[i], rightMax[i]) - height[i];
                           
        return res;
    }
};