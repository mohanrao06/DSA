# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow=head
        high=head
        while high is not None and high.next is not None:
            slow=slow.next
            high=high.next.next
        return slow



        