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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int N = 0;
        ListNode* temp = head;
        while(temp)
        {
            N++;
            temp = temp->next;        
        }
        
        int size = N/k;
        int remainder = N%k;
        vector<ListNode*> res; 
        temp = head;
        ListNode* prev = head;
        for(int i = 0; i < k; i++)
        {
            int elements = remainder > 0 ? (size + 1) : size;
            res.push_back(temp);
            if (prev)
            {
                while(temp and elements--)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next =nullptr;
                
            }            
            remainder --;     
        }
    return res;
    }
};