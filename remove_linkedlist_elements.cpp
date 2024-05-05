/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

#include <iostream>
#include <vector>
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
  ListNode *removeElements(ListNode *head, int val)
  {
    // Check if the head is null
    if (head == NULL)
    {
      return NULL;
    }

    // Create a dummy node to simplify edge cases
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = head;

    while (fast != nullptr)
    {
      // If the fastent node's value matches the value to be removed
      if (fast->val == val)
      {
        // Skip the fastent node
        slow->next = fast->next;
        delete fast;
        fast = slow->next; // Move to the next node
      }
      else
      {
        // Move both pointers forward
        slow = fast;
        fast = fast->next;
      }
    }

    ListNode *result = dummy->next;
    delete dummy;
    return result;
  }
};

/*
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
*/