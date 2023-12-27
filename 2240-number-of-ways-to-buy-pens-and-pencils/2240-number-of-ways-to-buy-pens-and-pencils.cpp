class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
     
        
        int penCost = 0;
        int remainingCost = 0;
        long long res = 0;
        while(penCost <= total)
        {
            remainingCost = total - penCost;
            //pencils = remainingCost/cost2;
            res+= remainingCost/cost2 + 1;
            penCost+= cost1;
        }
        return res;
    }
};