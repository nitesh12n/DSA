class Solution {
    
    bool isValid(unordered_map<char, int>& countS, unordered_map<char, int>& countT)
    {
        for(auto it : countT)
        {
            if(countS.find(it.first) == countS.end() or countS[it.first] < it.second)
                return false;
        }
    return true;
    }
public:
    string minWindow(string s, string t) {
      
        unordered_map<char, int>countS;
        unordered_map<char, int>countT;
        int m = s.size(), n = t.size();
        
        for(char ch : t)
            countT[ch]++;
        
        int l=0;
        while(l < m and countT.find(s[l]) == countT.end())
            l++;
        int r = l + n-1,i=l;
        
        while(i <= r)
        {
           countS[s[i]]++;   
           i++;
        }
        int start = -1, end = -1, res = INT_MAX;
        while( r < m)
        {
            if(isValid(countS, countT))
            {
                if(r - l + 1 < res)
                {
                    res = r - l + 1;
                    start = l;
                    end = r;
                }
                countS[s[l]]--;
                l++;
            }
            else
            {
                r++;
                countS[s[r]]++;
            }          
        }
        if(start == -1 or end == -1)
            return "";
        return s.substr(start, end - start + 1);
    }
};