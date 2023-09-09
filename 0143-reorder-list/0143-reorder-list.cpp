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
    
    ListNode* getMiddleNode(ListNode* head)
    {
        ListNode *fast = head;
        while(fast and fast->next)
        {
            head = head ->next;
            fast = fast->next->next;
        }
        return head;
    }
    ListNode* reverseList(ListNode *head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode *prev = nullptr, *curr = head, *next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;       
    }
    
public:
    void reorderList(ListNode *head) {
        
        
        ListNode *middle = getMiddleNode(head);
        ListNode *second = reverseList(middle);
        ListNode *first = head, *temp;
        
        while(second and second->next)
        {
            temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;
        }   
    }
};