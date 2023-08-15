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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == nullptr)
            return head;    
        
        ListNode* preHeadLess = new ListNode(0);
        ListNode* preHeadMore = new ListNode(0);
        ListNode* lessList = preHeadLess;
        ListNode* moreList = preHeadMore;

        
        ListNode* temp = head;
        
        while(temp!= nullptr)
        {
            if(temp->val < x)
            {
                lessList->next = temp;
                lessList = lessList->next;
            }
            else
            {
                moreList->next = temp;
                moreList = moreList->next;
            }
            temp = temp->next; 
        }
     moreList->next = nullptr;
     lessList->next = preHeadMore->next;
     return preHeadLess->next;   
    }
};