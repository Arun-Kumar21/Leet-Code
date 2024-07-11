

# 1190. Reverse Substrings Between Each Pair of Parentheses


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.
 

## Examples

Example 1:


```
Input: s = "(abcd)"
Output: "dcba"
```

Example 2:


```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
```

Example 3:

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
```


Constraints:

- `1 <= s.length <= 2000`

- `s` only contains lower case English characters and parentheses.

- It is guaranteed that all parentheses are balanced.
