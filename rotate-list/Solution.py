// https://leetcode.com/problems/rotate-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        length=0
        h=head
        if head==None:
            return head
        while h != None:
            h=h.next
            length+=1
        k=k % length
        if k==0:
            return head
        h=head
        for i in range(length-k-1):
            h=h.next
        n=h.next
        new_head=n
        h.next=None
        while n.next != None:
            n=n.next
        n.next=head
        return new_head