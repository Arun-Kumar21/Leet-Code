from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        dict = {}

        for i in range(len(heights)):
            dict[heights[i]] = names[i]


        heights.sort()
        heights.reverse()

        ans = []
        for i in range(len(heights)):
            ans.append(dict[heights[i]])

        return ans

