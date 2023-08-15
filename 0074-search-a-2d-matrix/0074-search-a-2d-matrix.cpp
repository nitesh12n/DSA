class Solution {
    int getRowIndex(vector<vector<int>>& matrix, int target)
    {
        int low = 0, high = matrix.size()-1;
        int res = -1;
        while(low <=high)
        {
            int mid = low + (high - low)/2;
            
            if(matrix[mid][0] == target)
                return mid;
            else if(matrix[mid][0] > target)
                high = mid - 1;
            else
            {
                res = mid;
                low = mid + 1;
            }
        }
    return res;
    }
    bool exists(vector<int>& arr, int target)
    {
        int low = 0, high = arr.size()-1;
        while(low <=high)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == target)
                return true;
            else if(arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
    return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = getRowIndex(matrix, target);
        
        return row != -1 and exists(matrix[row], target);
    }
};