class Solution {
    
    vector<pair<int,int>>getMapping(int n, vector<vector<int>>& board)
    {
        int value = 1;
        
        vector<pair<int,int>>mapping(n*n + 1);
        bool isReverse = false;
        for(int row = n-1; row>=0; row--)
        {
            for(int col = 0; col < n; col++)
            {
                int j  = isReverse ? n - 1 - col : col;
                mapping[value++] = {row, j};
            }
            isReverse = !isReverse;
        }
    return mapping;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
       
        int n = board.size();
        int destination = n*n;
        
        vector<pair<int,int>>mapping = getMapping(n, board);        
        vector<int>dist(destination + 1, -1);
        queue<int>q;
        
        q.push(1);
        dist[1] = 0;
        
        while(!q.empty())
        {
            int cell = q.front();
            q.pop();
            int end = min(cell + 6, destination);
            for(int i = cell + 1; i <= end; i++)
            {
                int row = mapping[i].first;
                int col = mapping[i].second;
                int next = board[row][col] == -1 ? i : board[row][col];
                
                if(dist[next] == -1)
                {
                    dist[next] = dist[cell] + 1;
                    q.push(next);
                }
            }
        }
        return dist[destination];
    }
};