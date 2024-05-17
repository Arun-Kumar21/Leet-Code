/*
Q2331. Evaluate Boolean Binary Tree
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
  bool evaluateTree(TreeNode *root)
  {
    // base case: leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
      return root->val == 1;
    }

    // evaluate left and right children
    bool leftChild = root->left ? evaluateTree(root->left) : false;
    bool rightChild = root->right ? evaluateTree(root->right) : false;

    // evaluate current node based on its value
    if (root->val == 2)
    {
      return leftChild || rightChild; // OR operation
    }
    else if (root->val == 3)
    {
      return leftChild && rightChild; // AND operation
    }

    return false; // default case, should not reach here if tree is valid
  }
};

/*
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
*/