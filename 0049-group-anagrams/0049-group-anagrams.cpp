class Solution {
    int getParent(vector<int>&parent, int i)
    {
        while(parent[i] != i)
            i= parent[i];
        return i;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<unordered_map<char, int>>m(n);
        
        vector<int>parent(n);
        for(int i=0; i <n; i++)
        {
            parent[i] = i;
            for(auto ch : strs[i])
                m[i][ch]++;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j= i +1; j <n; j++)
            {
                if(parent[j] == j and m[i] == m[j])
                    parent[j] = getParent(parent, i);
            }
        }
        unordered_map<int, vector<int>>list;
        
        
        for(int i =0 ; i<n;i++)
            list[parent[i]].push_back(i);
        
        vector<vector<string>>res;
        for(auto l : list)
        {
            vector<string>temp;
            for(auto i : l.second)
                temp.push_back(strs[i]);
            res.push_back(temp);
        }
        return res;
    }
};