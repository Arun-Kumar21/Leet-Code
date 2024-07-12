

# 1717. Maximum Score From Removing Substrings


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

You are given a string `s` and two integers `x` and `y`. You can perform two types of operations any number of times.

- Remove substring `"ab"` and gain `x` points.
  - For example, when removing `"ab"` from `"cabxbae"` it becomes `"cxbae"`.
- Remove substring `"ba"` and gain `y` points.
  - For example, when removing `"ba"` from `"cabxbae"` it becomes `"cabxe"`.

Return the *maximum* points you can gain after applying the above operations on `s`.
 

## Examples

Example 1:


```
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
```

Example 2:


```
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20.
```



Constraints:

- `1 <= s.length <= 10^5`

- `1 <= x, y <= 10^4`

- `s` consists of lowercase English letters.
