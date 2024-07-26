
# 523. Continuous Subarray Sum


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

A subarray is a contiguous part of an array.

 

## Examples

Example 1:
```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

Example 2:
```
Input: nums = [5], k = 9
Output: 0
```

Constraints:

`1 <= nums.length <= 3 * 10^4`

`2 <= k <= 10^4`

