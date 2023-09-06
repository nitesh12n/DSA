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
    int getLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            length++;
            head = head->next;        
        }
    return length;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int N = getLength(head);  
        int batchSize = N/k, extraNodesCount = N%k;
        ListNode*temp = head, *prev = head;
        vector<ListNode*> res; 
        
        while(k--)
        {
            int elements = extraNodesCount > 0 ? (batchSize + 1) : batchSize;
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
            extraNodesCount --;     
        }
    return res;
    }
};