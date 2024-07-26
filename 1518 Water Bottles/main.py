class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        num_water_bottles = numBottles

        remaining_bottles = 0
        while numBottles >= numExchange:

            remaining_bottles = numBottles % numExchange
            num_water_bottles += int(numBottles / numExchange)

            numBottles = int(numBottles / numExchange)
            numBottles += remaining_bottles

        return num_water_bottles
