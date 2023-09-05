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
public:
    ListNode* swapPairs(ListNode* head) {
        
        
     ListNode* prev = nullptr, *curr = head;
     
        if(head==nullptr || head->next == nullptr)
            return head;
    ListNode* newHead = head->next;
        
    while(curr && curr->next)
    {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        if(prev!=nullptr)
            prev->next = temp;
        temp->next = curr;
        prev = curr;
        curr = curr->next;       
    }
        return newHead;
    
        
    }
};