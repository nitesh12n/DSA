class TimeMap {
    unordered_map<string, vector<pair<int, string>>>m;
public:
    TimeMap() {
     m = {};   
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
      if(m.find(key) == m.end())
          return "";
        
      int left = 0, right = m[key].size()-1,res = -1;  
        
       while(left <= right)
       {
           int mid = left + (right-left)/2;
           if(m[key][mid].first <= timestamp)
           {
               res = left;
               left = mid + 1;
           }       
           else
               right = mid - 1;
       }
        if(res == -1)
            return "";
        return m[key][res].second;
           
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */