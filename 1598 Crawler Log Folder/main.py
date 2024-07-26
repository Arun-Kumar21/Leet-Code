from typing import List


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        fs = ["main"]

        for i in logs:
            if i[0] != ".":
                fs.append(i)

            if i == "../" and len(fs) > 1:
                fs.pop()

        return len(fs)-1

