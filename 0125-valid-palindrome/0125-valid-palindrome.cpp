class Solution {
public:
    bool isAplanumeric(char c)
    {
        c = tolower(c);
        
        return (c >='a' and c<='z') || (c>='0' and c<='9');
    }
    bool isPalindrome(string s) {
        
      int i = 0;
      int j = s.size()-1;
        
      while(i<j)
      {
          if(!isAplanumeric(s[i]))
          {
              i++;
              continue;
          }
          if(!isAplanumeric(s[j]))
          {
              j--;
              continue;
          }
          if(tolower(s[i]) != tolower(s[j]))
                return false;
          i++;
          j--;
             
      }
        return true;
    }
};