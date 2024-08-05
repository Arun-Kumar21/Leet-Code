class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        d = {}
        for s in arr:
            d[s] = 1 + d.get(s,0)

        for s in d:
            if d[s] == 1 and k == 1:
                return s
            elif d[s] == 1:
                k -= 1

        return "" 
