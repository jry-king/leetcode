#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * add corresponding digits of two lists to the same place of result list
 * O[max(m,n)] time complexity and O[max(m,n)] space complexity
 * m, n is the length of the two linked lists
 * 32 ms, faster than 27.63%
 * 11.8 MB, less than 5.14%
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int tempval = l1->val + l2->val; // value of current node
        int carry = tempval / 10;        // carry digit on current node
        ListNode *l3 = new ListNode(tempval % 10);
        ListNode *tempnode = l3;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2)
        {
            tempval = l1->val + l2->val + carry;
            carry = tempval / 10;
            tempnode->next = new ListNode(tempval % 10);
            tempnode = tempnode->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // one list or both lists are exhausted
        ListNode *remain = (NULL == l1) ? l2 : l1;
        while (remain && carry)
        {
            tempval = remain->val + carry;
            carry = tempval / 10;
            tempnode->next = new ListNode(tempval % 10);
            tempnode = tempnode->next;
            remain = remain->next;
        }
        while (remain)
        {
            tempnode->next = new ListNode(remain->val);
            tempnode = tempnode->next;
            remain = remain->next;
        }
        if (carry)
        {
            tempnode->next = new ListNode(carry);
        }
        return l3;
    }
};

/*
 * use l1 directly instead of allocate new listnodes
 * O[max(m,n)] time complexity and O[max(m,n)] space complexity
 * m, n is the length of the two linked lists
 * 24 ms, faster than 77.50%
 * 11.3 MB, less than 5.14%
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = l1;
        ListNode *lastnode = NULL;
        int carry = 0;

        while (l1 && l2)
        {
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            lastnode = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        // one list is exhausted
        if (l1 || l2)
        {
            lastnode->next = l1 ? l1 : l2;
            while (lastnode->next && carry)
            {
                lastnode = lastnode->next;
                lastnode->val += carry;
                carry = lastnode->val / 10;
                lastnode->val %= 10;
            }
            if (carry)
            {
                lastnode->next = new ListNode(carry);
            }
        }
        // both lists are exhausted
        else if (carry)
        {
            lastnode->next = new ListNode(carry);
        }
        return l3;
    }
};