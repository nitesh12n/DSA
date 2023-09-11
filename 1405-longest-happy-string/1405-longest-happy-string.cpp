class Solution {
public:
    
    
    
string longestDiverseString(int a, int b, int c) {
    // max heap stores {no. of times we can use char, char}
    priority_queue<pair<int, char>> pq;
    
    if(a > 0){
        pq.push({a, 'a'});
    }
    
    if(b > 0){
        pq.push({b, 'b'});
    }
    
    if(c > 0){
        pq.push({c, 'c'});
    }
    
    string ans;
    while(pq.size() != 0){
    // first maximum
        char curL = pq.top().second;
        int occL = pq.top().first;
        
        pq.pop();
        
        if(ans.size() == 0 || ans.back() != curL){
            int times = 0;
            times = min(occL, 2);
            for(int i=0; i<times; i++){
                ans += curL;
            }

            occL -= times;
            if(occL > 0){
                pq.push({occL, curL});
            }

        }
        else{  // second maximum 

            // add one ocurance of char of second max freq if it exists.
            if(pq.size() == 0){
                break;
            }

            char curS = pq.top().second;
            int occS = pq.top().first;
            pq.pop();

            ans += curS;
            occS--;
            if(occS > 0){
                pq.push({occS, curS});
            }

            // return to the pq the max char we popped out in if clause:
            pq.push({occL, curL});            

        }
        
    }
 
    return ans;
}
};