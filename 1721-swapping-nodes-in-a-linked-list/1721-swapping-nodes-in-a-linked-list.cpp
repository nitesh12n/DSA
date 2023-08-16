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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* begin = head;        
        
        while(--k)
            begin = begin->next;
        
        
        ListNode* end = head, *fast = begin;
        while(fast->next)
        {
            end = end->next;
            fast = fast->next;
        }
        
        int temp = begin->val;
        begin->val = end->val;
        end->val = temp;
        return head;
    }
};