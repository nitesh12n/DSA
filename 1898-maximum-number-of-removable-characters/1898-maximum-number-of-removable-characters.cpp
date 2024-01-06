class Solution {
    bool isSubsequence(string s, string t) {
        
        int i = 0,j = 0;
        
        while(j<s.size() and i<t.size())
        {
            if(s[j] == t[i])
                j++;
            i++;
        }
        return j== s.size();
    }
    
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int k = 0;
        
        int low = 0, high =  removable.size();
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            string temp = s;
            
            for(int i=0; i<mid; i++){
                temp[removable[i]]='0';
            }
            
            if(isSubsequence(p, temp))
            {
                k = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
            
        }
        
        return k;
        
        
    }
};