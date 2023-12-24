class Solution {
    unordered_map<char, pair<int,int>> m = {{'N', {-1,0}}, {'S', {1,0}}, {'E', {0,1}}, {'W', {0,-1}}};
public:
    bool isPathCrossing(string path) {
        
        unordered_set<string>vis;
        int currPosX = 0, currPosY = 0;
        vis.insert(to_string(currPosX) 
                            + "," + to_string(currPosY));
        for(char ch : path)
        {
            currPosX+= m[ch].first;
            currPosY+= m[ch].second;

            string key = to_string(currPosX) 
                            + "," + to_string(currPosY);
            
            if(vis.find(key) != vis.end())
                return true;
            vis.insert(key);
        }
    return false;
    }
};