/*
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *doubleIt(ListNode *head)
  {
    stack<ListNode *> container;
    ListNode *ptr = head;

    // Filling stack
    while (ptr)
    {
      container.emplace(ptr);
      ptr = ptr->next;
    }

    int carry = 0;
    ListNode *res = container.top();
    container.pop();

    if (res->val * 2 >= 10)
    {
      carry = 1;
    }

    res->val = res->val * 2 % 10;

    while (!container.empty())
    {
      ListNode *node = container.top();
      container.pop();

      int val = node->val;

      node->val = (node->val * 2) % 10 + carry;

      if (val * 2 >= 10)
      {
        carry = 1;
      }
      else
      {
        carry = 0;
      }

      node->next = res;
      res = node;
    }

    if (carry)
    {
      ListNode *node = new ListNode(1);
      node->next = res;
      res = node;
    }

    return res;
  }
};

/*
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/