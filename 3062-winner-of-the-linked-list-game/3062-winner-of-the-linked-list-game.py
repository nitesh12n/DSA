# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        
        even, odd = 0, 0
        
        temp = head
        while head and head.next:
            
            even+= head.val > head.next.val
            odd+= head.val < head.next.val
            
            head = head.next.next
            
        if even > odd:
            return 'Even'
        elif even < odd:
            return 'Odd'
        return 'Tie'
        
            

            
        