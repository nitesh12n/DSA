class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size()/4, count = 1;
        
        for(int i = 0; i < arr.size() - n; i++)
        {
            if(arr[i] == arr[i + n])
                return arr[i];              
        }
    return -1;
    }
};