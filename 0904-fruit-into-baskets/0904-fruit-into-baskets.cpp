class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        if(fruits.size() == 1)
            return 1;
        int l =0, r = 1;
        
        int res = 1;
        unordered_map<int, int>m;
        m[fruits[l]]++;
        
        while(l <=r and r < fruits.size())
        {
            if(m.find(fruits[r]) == m.end() and m.size() == 2)
            {
                m[fruits[l]]--;
                if(m[fruits[l]] == 0)
                    m.erase(fruits[l]);
                l++;
            }
            else
            {
                m[fruits[r]]++;
                res = max(res, r - l + 1);
                r++;
            }
        }
    return res;
    }
};