class Solution {

    public int minimumLength(String s) {
        int i,j;
        i=0; j= s.length()-1;
        while(i<j){
            char c1 = s.charAt(i);
            char c2= s.charAt(j);
            if(c1==c2){
                char temp = c1;
                while(c1==temp && i<j){
                    i++;
                    temp = s.charAt(i);
                }
                
                temp = c2;
                while(c2==temp && i<=j){
                    j--;
                    temp = s.charAt(j);
                }
            }
            else
            {
                break;
            }
        }
        if(j < i)
            return 0;
        if(i == j)
            return 1;
        //if(i == j - 1)
        //    return s.charAt(i) == s.charAt(j) ? 0 : 2;
        return j-i+1;
    }
}