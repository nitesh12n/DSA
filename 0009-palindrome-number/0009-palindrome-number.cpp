class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0 or (x%10 == 0. and x != 0))
            return false;
        
         int rev = 0;
         while(x > rev)
           {
               rev = rev*10 + x%10;
               x/=10;
           }
    return x == rev or x == rev/10;
    }
};