/*
Q2. Add Two Numbers
*/

#include <bits/stdc++.h>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0;
    ListNode *dummy = new ListNode(0); // Dummy node to simplify the result list creation
    ListNode *ptr = dummy;             // Pointer to traverse and build the result list

    while (l1 || l2 || carry)
    {
      int sum = carry;
      if (l1)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum / 10;
      ptr->next = new ListNode(sum % 10);
      ptr = ptr->next;
    }

    return dummy->next; // The result list starts from the next node of the dummy node
  }
};
