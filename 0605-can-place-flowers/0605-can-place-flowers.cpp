class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        bool isLeftEmpty;
        bool isRightEmpty;
        int size = flowerbed.size();
        for(int i =0;i<size;i++)
        {
            if(n==0)
                break;
            if(flowerbed[i]==0)
            {
                isLeftEmpty = i==0 || flowerbed[i-1] == 0;
                isRightEmpty = i== size-1 || flowerbed[i+1]==0;

                if(isLeftEmpty and isRightEmpty)
                    n--, i++;                
            }
        }
        return n==0;
    }
};