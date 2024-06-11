
# 523. Continuous Subarray Sum


[![MIT License](https://camo.githubusercontent.com/5905bd5b7eec90ffe4233eafa2f0ff45311046010018638745e5720cb996f504/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d456173792d627269676874677265656e)]()

Given two arrays `arr1` and `arr2`, the elements of `arr2` are distinct, and all elements in `arr2` are also in `arr1`.

Sort the elements of `arr1` such that the relative ordering of items in `arr1` are the same as in `arr2`. Elements that do not appear in `arr2` should be placed at the end of `arr1` in ascending order.
 

## Examples

Example 1:
```
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

Example 2:
```
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
```

Constraints:

`1 <= heights.length <= 1000`

`1 <= heights[i] <= 1000`

