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
    ListNode* reverseList(ListNode* head) {
        
       if(head == nullptr or head->next == nullptr)
           return head;
        
       ListNode *prev=nullptr, *curr = head, *next = head->next;
    
        while(curr !=nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* middleNode(ListNode* head) {
        
        if(head == nullptr or head->next == nullptr)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != nullptr and fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* firstHalfEnd = middleNode(head);
        
        ListNode* reverseHead = reverseList(firstHalfEnd->next);
        ListNode* reverse = reverseHead;
        ListNode* firstHalf = head;
        bool res = true;
        while(res and reverse != nullptr)
        {
            if(firstHalf->val != reverse ->val)
                res =  false;
            firstHalf = firstHalf->next;
            reverse = reverse->next;
        }
        firstHalfEnd ->next  = reverseList(reverseHead);
        return res;
        
    }
};