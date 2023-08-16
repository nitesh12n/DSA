/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode *head)
    {
        int length = 0;
        while(head)
        {
            head = head->next;
            length++;
        }
    return length;
    }
    ListNode* getUpdatedPointer(ListNode* p, int len)
    {
        while(len-- and p)
            p = p->next;
        return p;
    }
    ListNode *intersectionNode(ListNode *p1, ListNode *p2) 
    {    
        while(p1 and p2 and p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        
        ListNode* p1 = headA, *p2 = headB;
        
        
        if(l1 > l2)
            p1 = getUpdatedPointer(p1, l1-l2);
        else if(l1 < l2)
            p2 = getUpdatedPointer(p2, l2-l1);
        
        return intersectionNode(p1, p2);
        
    }
};