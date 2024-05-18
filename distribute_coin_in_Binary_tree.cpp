/*
Q979 Distribute Coins in binary tree
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
  int moves = 0;

  int dfs(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    // post order traversal
    int leftChildReq = dfs(root->left);
    int rightChildReq = dfs(root->right);

    // handle parent
    root->val = leftChildReq + rightChildReq + (root->val - 1);
    moves += abs(root->val);

    return root->val;
  }

  int distributeCoins(TreeNode *root)
  {
    dfs(root);
    return moves;
  }
};

/*
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
*/