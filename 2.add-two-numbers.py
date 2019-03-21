# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# add corresponding digits of two lists to the same place of result list
# 128 ms, faster than 27.58%
# 13.3 MB, less than 5.21%
'''
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode(0)
        tempnode = l3
        carry = 0           # whether there is a carry on that digit
        
        while (l1 is not None or l2 is not None):      
            tempval = 0
            # one of the lists is exhausted
            if (l1 is None):
                tempval = (carry + l2.val) % 10
                carry = (carry + l2.val) // 10
                l2 = l2.next
            elif (l2 is None):
                tempval = (carry + l1.val) % 10
                carry = (carry + l1.val) // 10
                l1 = l1.next
            
            else:
                temp = l1.val + l2.val
                tempval = (carry + temp) % 10
                carry = (carry + temp) // 10
                l1 = l1.next
                l2 = l2.next
            tempnode.next = ListNode(tempval)
            tempnode = tempnode.next
        
        # whether the result is one digit more than the larger addend
        if (carry == 1):
            tempnode.next = ListNode(1)
        l3 = l3.next
        return l3
'''

# optimize last solution by splitting the processing of the shared part and different part of two lists
# 108 ms faster than 68.73%
# 13.3MB, less than 5.21%
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        firstval = l1.val + l2.val
        carry = firstval // 10           # whether there is a carry on that digit
        l3 = tempnode = ListNode(firstval % 10)
        l1 = l1.next
        l2 = l2.next
        
        while (l1 is not None and l2 is not None):
            tempval = carry + l1.val + l2.val
            carry = tempval // 10
            l1 = l1.next
            l2 = l2.next
            tempnode.next = ListNode(tempval % 10)
            tempnode = tempnode.next
        
        # one of the lists is exhausted
        remain = None
        if (l1 is not None):
            remain = l1
        elif (l2 is not None):
            remain = l2
        # take care of carry number if still exists
        while (remain is not None and carry != 0):
            tempval = remain.val + carry
            carry = tempval // 10
            remain = remain.next
            tempnode.next = ListNode(tempval % 10)
            tempnode = tempnode.next
            
        # as soon as carry is 0 the rest part is the same as those in the longer list
        while (remain is not None):
            tempnode.next = ListNode(remain.val)
            remain = remain.next
            tempnode = tempnode.next
        # the result is one node longer than the longer addend
        if (carry):
            tempnode.next = ListNode(carry)
        
        return l3