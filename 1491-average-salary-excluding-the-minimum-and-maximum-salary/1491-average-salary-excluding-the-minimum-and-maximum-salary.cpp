class Solution {
public:
    double average(vector<int>& salary) {
        
        int minimum=INT_MAX;
        int maximum=0;
        double sum=0;
        for(auto i:salary)
        {
            minimum = min(minimum, i);
            maximum = max(maximum, i);
            sum+=i;
        }
        return (sum-minimum-maximum)/(salary.size()-2);
    }
};