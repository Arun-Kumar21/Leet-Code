/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
*/

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Main logic is similar as deleting an element from middle of array;

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    ListNode *fast = node;
    ListNode *slow = node;

    while (fast->next)
    {
      int val = fast->next->val;
      fast->val = val;

      slow = fast;

      fast = fast->next;
    }

    slow->next = NULL;
  }
};

/*
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
*/