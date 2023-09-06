/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    
    
public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*>mappings;
        queue<Node*>q;
        Node* newGraph = new Node(node->val);
        mappings[node] = newGraph;
        q.push(node);
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();        
            Node* newGraphNode = mappings[temp];
            for(auto n : temp->neighbors)
            {
                if(mappings.find(n) == mappings.end())
                {
                    q.push(n);      
                    mappings[n] = new Node(n->val);   
                }
                newGraphNode->neighbors.push_back(mappings[n]);
            }            
        }
    return newGraph;
    }
};