class Solution {
      
public:
    int openLock(vector<string>& deadends, string target) {
        
        set<string>s;
        
        for(auto it : deadends)
            s.insert(it);
        
        queue<string>q;
        q.push("0000"); 
        if(s.count("0000"))
            return -1;
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();        
            while(size--)
            {
                string node = q.front();
                q.pop();
                if(node == target)
                    return dist;
                for(int i = 0; i < 4; i++)
                {
                    for(int d = -1; d <=1; d+=2)
                    {
                        string temp = node;
                        temp[i] = (temp[i] - '0' + d + 10) % 10 + '0';
                        if(s.count(temp) == 0)
                        {
                            q.push(temp);
                            s.insert(temp);
                        }
                    }
                } 
            }
            dist++;
        }
    return -1;
    }
};