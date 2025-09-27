# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        strl=""
        if head is None :
            print ("empty")
            return
        temp=head
        while temp:
            strl=strl+str(temp.val)
            temp=temp.next
        return int(strl,2)



        