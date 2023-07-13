class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        int letterCount=0;
        map<char, int>m;
        for(int i=0; i<words.size();i++)
        {
            for(auto ch: words[i])
            {
                if(m.find(ch)==m.end())
                {
                    letterCount++;
                    m[ch]=0;
                }
            }
        }
        vector<vector<char>>adj(26);
        for(int i=1; i<words.size();i++)
        {
            string s1 = words[i-1];
            string s2 = words[i];
            
            int j = 0;
            
            while(j < s1.size() && j < s2.size() && s1[j] == s2[j])
                j++;
            
            if(j<s1.size() && j<s2.size())
            {
                adj[s1[j]-'a'].push_back(s2[j]);   
                m[s2[j]]++;
            }     
            else if(j < s1.size() and j == s2.size())
                return "";
        }
        queue<char>q;
        string res;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second==0)
                q.push(it->first);
        }
        
        while(!q.empty())
        {
            char l = q.front();
            q.pop();
            res+=l;
            
            
            for(auto i : adj[l-'a'])
            {
                m[i]--;
                if(m[i]==0)
                    q.push(i);
            }
        }
        if(res.size() == m.size())
            return res;  
        return "";
        
        
        
    }
};