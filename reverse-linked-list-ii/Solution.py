// https://leetcode.com/problems/reverse-linked-list-ii

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        left-=1
        right-=1
        h=head
        prev=None
        for i in range(left):
            prev=h
            h=h.next
        left_node=prev
        right_node=h
        l=left
        r=right
        prev=h
        h=h.next
        while l<r:
            n=h.next
            h.next=prev
            prev=h
            h=n
            l+=1
        if left_node != None:
            left_node.next=prev
        else:
            head=prev
        if right_node != None:
            right_node.next=h
        return head