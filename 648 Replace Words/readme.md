
# 1002. Find Common Characters


[![MIT License](https://camo.githubusercontent.com/472690903f70a87b6ffdc31598aa41239adc4177f8cb9d368af04e6915a57a33/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f446966666963756c74792d4d656469756d2d6f72616e6765)]()

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root `"help"` is followed by the word `"ful"`, we can form a derivative `"helpful"`.

Given a `dictionary` consisting of many roots and a `sentence` consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the `sentence` after the replacement.

## Examples

Example 1:
```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

Example 2:
```
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```

Constraints:

`1 <= dictionary.length <= 1000`

`1 <= dictionary[i].length <= 100`

