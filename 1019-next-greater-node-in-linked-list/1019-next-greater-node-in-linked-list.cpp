/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    int getGreaterNode(ListNode* node)
    {
        ListNode* temp = node->next;
        
        while(temp != nullptr and temp->val <= node->val)
        {
           temp = temp->next; 
        }
        if(temp != nullptr)
            return temp->val;
        
        return 0;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        
        ListNode* curr = head;
        vector<int>answer;
        while(curr != nullptr)
        {
            int val = getGreaterNode(curr);
            answer.push_back(val);
            curr = curr->next;
        }
        return answer;
    }
};