
# 523. Continuous Subarray Sum


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

Given an integer array nums and an integer k, return `true` if `nums` has a good subarray or `false` otherwise.

A good subarray is a subarray where:

- its length is at least two, and
- the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer `n` such that `x = n * k`. `0` is always a multiple of `k`.

## Examples

Example 1:
```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
```

Example 2:
```
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
```

Constraints:

`1 <= nums.length <= 10^5`

`0 <= nums[i] <= 10^9`

