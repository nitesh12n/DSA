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
    
    ListNode* reverseFirstKNodes(ListNode* head, int k)
    {
        ListNode* prev = nullptr, *curr = head, *temp;
        
        while(k-- and curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next  = curr;
    return prev;
        
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* preLeft = preHead;
        
        int k = right - left + 1;
        while(--left)
        {
            preLeft = preLeft->next;
        }
        
        preLeft->next = reverseFirstKNodes(preLeft->next, k);
        return preHead->next; 
    }
};