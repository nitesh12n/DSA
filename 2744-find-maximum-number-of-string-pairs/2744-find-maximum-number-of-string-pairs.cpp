class Solution {
    
    bool canBePaired(string& a, string& b)
    {
        if(a.size() != b.size())
            return false;
        
        int i = 0, j = b.size() - 1;
        
        while(i < b.size() and j>=0)
        {
            if(a[i] != b[j])
                return false;
            i++;
            j--;
        }
    return true;
    }
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            {
                if(canBePaired(words[i], words[j]))
                {
                    cout<<words[i]<< " " << words[j] <<endl;
                    res++;
                }
            }
        }
    return res;
    }
};