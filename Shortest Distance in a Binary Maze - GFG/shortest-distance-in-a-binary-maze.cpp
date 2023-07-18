//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dist(n, vector<int>(m,1e6));
    queue<pair<int, pair<int,int>>>q;
    dist[source.first][source.second]=0;
    q.push({0,{source.first, source.second}});
    
    vector<int>deltaX = {-1,0,1,0};
    vector<int>deltaY = {0,1,0,-1};

    while(!q.empty())
    {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if(x == destination.first && y==destination.second)
            return d;
            
        for(int i=0;i<4;i++)
        {
            int newX = x+deltaX[i];
            int newY = y+deltaY[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == 1)
            {
                if(dist[newX][newY] > d + 1)
                {
                    dist[newX][newY] = d+1;
                    q.push({dist[newX][newY], {newX,newY}});
                }
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends