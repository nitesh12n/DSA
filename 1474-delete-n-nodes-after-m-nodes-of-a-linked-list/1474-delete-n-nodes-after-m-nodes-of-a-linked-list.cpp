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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        
        
        ListNode*temp = head;
        while(temp)
        {
            int i = 1, j = 0;
            while( i++ < m and temp)
                temp = temp->next;
            
            while( j++ < n and temp and temp->next)
            {
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
            } 
            if(temp)
                temp = temp->next;
        }
        return head;
    }
};