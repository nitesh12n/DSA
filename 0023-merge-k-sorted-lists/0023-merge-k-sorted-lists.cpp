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
    
    ListNode* mergeLists(ListNode* head1, ListNode* head2)
    {
        ListNode* preHead = new ListNode(0);
        ListNode* iter = preHead;
        
        
        while(head1 and head2)
        {
          if(head1->val < head2->val)
          {
              iter->next = head1;
              head1 = head1->next;
          }
          else
          {
              iter->next = head2;
              head2 = head2->next;
          }
           iter = iter->next; 
        }
        if(head1)
            iter->next = head1;
        if(head2)
            iter->next = head2;
        
        return preHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *head = nullptr;
        
        int n = lists.size();
        if(n == 0)
            return head;
        
        int interval = 1;
        while(interval < n)
        {
            for(int i = 0; i < n - interval; i+= interval*2)
                lists[i] = mergeLists(lists[i], lists[i + interval]);
            interval*=2;
        }
        
        return lists[0];
    }
};