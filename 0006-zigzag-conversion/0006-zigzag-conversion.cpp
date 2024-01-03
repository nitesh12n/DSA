class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        vector<vector<char>>res(numRows, vector<char>({}));
        bool direction = false;
        int row = 0;
        for(int i = 0; i < s.size(); i++)
        {
            
            //if(res.size() <= row)
              //  res[row].push_back(s[i]);
            //else
                res[row].push_back(s[i]);
            
            if(direction == false)
                row++;
            else
                row--;
            
            if(row == numRows)
            {
                row-=2;
                direction = !direction;
            }
            if(row < 0)
            {
                row+=2;
                direction = !direction;
            }   
        }
        string ans;
        for(auto row : res)
        {
            for(auto ch : row)
                ans+= ch;
        }
        return ans;
        
    }
};