class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        if(fruits.size() == 1)
            return 1;
        int firstFruitType = -1,secondFruitType = -1;
        int firstFruitCount = 0,secondFruitCount = 0;
        
        
        int l =0, r = 1;
        firstFruitType = fruits[0];
        firstFruitCount = 1;
        secondFruitType = -1;
        int res = 0;
        while(l <=r and r < fruits.size())
        {
            if(firstFruitType == fruits[r])
            {
                firstFruitCount++;
                r++;
            }
            else if(secondFruitType == -1 or secondFruitType == fruits[r])
            {
                secondFruitType = fruits[r];
                secondFruitCount++;
                r++;
            } 
            else
            {
                if(fruits[l] == firstFruitType)
                    firstFruitCount--;
                else
                    secondFruitCount--;
                
                if(secondFruitCount == 0)
                    secondFruitType = -1;

                if(firstFruitCount == 0)
                {
                    firstFruitCount = secondFruitCount;
                    firstFruitType = secondFruitType;
                    secondFruitCount = 0;
                    secondFruitType = -1;
                }
                
                l++;
            }
            res = max(res, firstFruitCount + secondFruitCount);
        }
    return res;
    }
};