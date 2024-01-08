/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
    
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        auto dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0], cols = dimensions[1];
        int res = -1, i = 0, j = cols - 1;
        while(i < rows and j >= 0)
        {
            if(binaryMatrix.get(i, j) == 0)
                i++;
            else
                res = j--;
        }
        return res;
    }
};