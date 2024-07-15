

# 2196. Create Binary Tree From Descriptions

[![Difficulty Hard](https://img.shields.io/badge/Difficulty-Meduim-orange)]()


You are given a 2D integer array `descriptions` where `descriptions[i] = [parenti, childi, isLefti]` indicates that `parenti` is the **parent** of `childi` in a **binary** tree of **unique** values. Furthermore,

- If `isLefti == 1`, then `childi` is the left child of `parenti`.
- If `isLefti == 0`, then `childi` is the right child of `parenti`.

Construct the binary tree described by `descriptions` and return its **root**.

The test cases will be generated such that the binary tree is **valid**.
 

## Examples

Example 1:


[![Example 1](https://assets.leetcode.com/uploads/2022/02/09/example1drawio.png)]()

```
Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
```

Example 2:

[![Example 2](https://assets.leetcode.com/uploads/2022/02/09/example2drawio.png)]()

```
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
```


Constraints:

- `1 <= descriptions.length <= 10^4`

- `descriptions[i].length == 3`

- `1 <= parenti, childi <= 10^5`

- `0 <= isLefti <= 1`

- The binary tree described by `descriptions` is valid.
