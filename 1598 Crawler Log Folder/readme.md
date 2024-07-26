

# 1598. Crawler Log Folder


[![MIT License](https://camo.githubusercontent.com/5905bd5b7eec90ffe4233eafa2f0ff45311046010018638745e5720cb996f504/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d456173792d627269676874677265656e)]()

The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

- `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).

- `"./"` : Remain in the same folder.

- `"x/"` : Move to the child folder named `x` (This folder is guaranteed to always exist).
You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.

The file system starts in the main folder, then the operations in `logs` are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.
 

## Examples

Example 1:

[![Example 1](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)]()

```
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```

Example 2:

[![Example 1](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)]()

```
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```


Example 3:

```
Input: logs = ["d1/","../","../","../"]
Output: 0
```


Constraints:

- `1 <= logs.length <= 10^3`

- `2 <= logs[i].length <= 10`

- `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.

- `logs[i]` follows the format described in the statement.

- Folder names consist of lowercase English letters and digits.

