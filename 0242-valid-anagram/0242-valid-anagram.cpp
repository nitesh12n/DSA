class Solution {
public:
    bool isAnagram(string s, string t) {
      
        unordered_map<int, int>m;
        
        for(auto ch : s)
            m[ch]++;
        
        for(auto ch : t)
        {
          if(m.find(ch) == m.end())
              return false;            
          m[ch]--;

        }
        
        for(auto i : m)
            if(i.second>0)
                return false;
        
        return true;
    }
};