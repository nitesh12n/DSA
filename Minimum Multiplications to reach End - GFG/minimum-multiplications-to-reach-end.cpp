//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       int mod = 100000;
       vector<int>dist(mod, 1e6);
       
       queue<pair<int,int>>q;
       
       dist[start]=0;
       q.push({0,start});
       
       while(!q.empty())
       {
           int steps = q.front().first;
           int n = q.front().second;
           q.pop();
           if(n==end)
            return steps;
           for(int i=0;i<arr.size();i++)
           {
               int product = (n*arr[i])%mod;
               if(dist[product] > steps + 1)
               {
                   dist[product] = steps+1;
                   q.push({dist[product], product});
               }
           }
       }
       if(dist[end]==1e6)
            return -1;
        return dist[end];
       
       
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends