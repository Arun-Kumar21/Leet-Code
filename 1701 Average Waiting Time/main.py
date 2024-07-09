from typing import List


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        waiting_time = [0] * len(customers)
        chef_q = [0] * len(customers)

        chef_q[0] = customers[0][0] + customers[0][1]
        waiting_time[0] = customers[0][1]

        for i in range(1, len(customers)):
            arrival, time = customers[i]
            chef_q[i] = max(chef_q[i - 1], arrival) + time
            waiting_time[i] = chef_q[i] - arrival

        avg_waiting_time = sum(waiting_time) / len(waiting_time)

        return avg_waiting_time
