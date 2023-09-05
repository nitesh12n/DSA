/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*>mapping;
        
        Node* newIter = new Node(head->val);
        mapping[head] = newIter;
        Node* newHead = newIter;
        
        while(head!= nullptr)
        {            
            if(head->next and mapping.find(head->next) == mapping.end())
                mapping[head->next] = new Node(head->next->val);
            
            if(head->random and mapping.find(head->random) == mapping.end())
                mapping[head->random] = new Node(head->random->val);                
            newIter->next = mapping[head->next];
            newIter->random = mapping[head->random];
        head = head->next;
        newIter = newIter->next;
        }
    return newHead;
    }
};