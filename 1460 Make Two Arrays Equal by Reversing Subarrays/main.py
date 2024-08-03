class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        res = True
        d = {}

        for n in target:
            d[n] = 1 + d.get(n, 0)

        for n in arr:
            if n not in d or d[n] == 0:
                res = False
                break

            d[n] -= 1
        return res
