class Solution {
public:
    bool isUnique(string s)
    {
        set<char> m;

        for(int i = 0; i<s.size(); i++)
        {
            if(m.find(s[i]) == m.end())
                m.insert(s[i]);
            else
                return false; 
        }
        return true;
    }
    void maxLength(vector<string>& arr, string temp, int i, int& m)
    {
        if(i == arr.size())
        {
            m = max(m, (int)temp.size());
            return;
        }
        //nottake
        maxLength(arr, temp, i+1, m);
        //take
        if(isUnique(temp + arr[i]))
             maxLength(arr, temp + arr[i], i+1, m);
    }
    int maxLength(vector<string>& arr) {
        int m = 0;
        maxLength(arr, "", 0, m);
        return m;
    }
};