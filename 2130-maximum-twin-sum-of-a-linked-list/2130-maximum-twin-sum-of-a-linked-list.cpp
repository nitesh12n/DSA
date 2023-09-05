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
    int pairSum(ListNode* head) {
        
        stack<int>st;
        ListNode* fast = head, *middle = head;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            middle = middle ->next;
        }
        while(middle)
        {
            st.push(middle->val);
            middle = middle ->next;
        }
        ListNode* start = head;
        int res = 0;
        while(!st.empty())
        {
            res = max(res, st.top() + start->val);
            st.pop();
            start = start->next;
        }
    return res;
    }
};