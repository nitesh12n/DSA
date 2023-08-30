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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* prehead = new ListNode(0, head);
        ListNode *temp = prehead, *fast = prehead;
        while(n-- and fast)
        {
            fast = fast->next;
        }
        while(fast and fast->next)
        {
            temp = temp->next;
            fast = fast->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        head = prehead->next;
        delete prehead;
        delete del;
        return head;
    }
};