# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        mp = {}
        while head:
    
            mp[head.val] = mp.get(head.val, 0) + 1
            head = head.next
            
        newList = ListNode()
        res = newList
        for value in mp.values():
            
            newNode = ListNode(value)
            newList.next = newNode
            newList = newList.next
        
        return res.next
            
            
            
            
        