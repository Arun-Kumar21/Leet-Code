/*
Q1325. Delete Leaves With a Given Value
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *removeLeafNodes(TreeNode *root, int target)
  {
    if (root == nullptr)
    {
      return root;
    }

    // use postorder travesal

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->val == target && root->left == nullptr && root->right == nullptr)
    {
      // set null in place of target value
      return nullptr;
    }

    return root;
  }
};

/*
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left).
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
*/