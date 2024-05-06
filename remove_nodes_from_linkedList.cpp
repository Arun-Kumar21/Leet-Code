/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.
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
  ListNode *removeNodes(ListNode *head)
  {
    // Maintain stack to reverse the linkedList;
    stack<ListNode *> container;

    ListNode *ptr = head;
    while (ptr)
    {
      // Fill stack
      container.push(ptr);
      ptr = ptr->next;
    }

    // Last element always in resultant LL
    ListNode *res = container.top();
    container.pop();

    int maxVal = res->val;

    while (!container.empty())
    {
      ListNode *node = container.top();
      container.pop();

      if (node->val < maxVal)
      {
        continue;
      }
      else
      {
        // Insert new max value at head of LL

        node->next = res;
        res = node;

        maxVal = node->val;
      }
    }

    return res;
  }
};

/*
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
*/