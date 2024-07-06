class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        pos, direction = 1, 1

        while time > 0:
            if pos == n:
                direction = 0
            if pos == 1:
                direction = 1

            if direction == 1:
                pos += 1
            if direction == 0:
                pos -= 1

            time -= 1

        return pos
