class Solution {
    static bool customSort(const string& a, const string& b)
    {
        return a+b > b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>stringNums;
        string res;
        
        for(auto num : nums)
            stringNums.push_back(to_string(num));
        
        sort(stringNums.begin(), stringNums.end(), customSort);
        
        if(stringNums[0] == "0")
            return "0";
        for(auto strNum : stringNums)
            res+=strNum;
        
        return res;
    }
};