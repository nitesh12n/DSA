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
        
        while(fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* middle = middleNode(head);
        
        ListNode* reverseHead = reverseList(middle);
        
        while(reverseHead != nullptr and head != middle)
        {
            if(head->val != reverseHead ->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
        
    }
};