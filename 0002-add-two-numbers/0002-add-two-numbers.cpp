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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        
        ListNode* preHead = new ListNode(0);
        ListNode* resList = preHead;
        
        while(l1 || l2 || carry)
        {
            int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = value/10;
            value = value%10;
            resList->next = new ListNode(value);
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            resList = resList->next;
        }
        
        return preHead->next;
    }
};