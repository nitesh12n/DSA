# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        
        temp1, temp2 = list1, list2
        i = 1
        while i < a:
            temp1 = temp1.next
            i+=1
        j = i
        temp2 = temp1
        
        while j <= b + 1:
            temp2 = temp2.next
            j+=1
        
        list2end = list2
        while list2end.next:
               list2end = list2end.next 
        
        temp1.next = list2
        list2end.next = temp2
        
        return list1
            
            
           
        
            
            
            