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
        int res = -1, i = 0, j = dimensions[1] - 1;
        while(i < dimensions[0] and j >= 0)
        {
            if(binaryMatrix.get(i, j) == 0)
                i++;
            else
                res = j--;
        }
    return res;
    }
};