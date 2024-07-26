
# 167. Two Sum II - Input Array Is Sorted


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.
 

## Examples

Example 1:

[![example](https://assets.leetcode.com/uploads/2019/05/02/tree.png)]()

```
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

Example 2:
```
Input: root = [0,null,1]
Output: [1,null,1]
```

Constraints:

The number of nodes in the tree is in the range `[1, 100]`.

`0 <= Node.val <= 100`

All the values in the tree are unique.