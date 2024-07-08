class Solution:
    def find_the_winner(self, n: int, k: int) -> int:

        # Time complexity - O(n^2)

        circular_list = [x for x in range(1, n + 1)]
        start_pos = 0

        while len(circular_list) > 1:
            start_pos = (start_pos + k - 1) % len(circular_list)
            circular_list.pop(start_pos)    # In worst can it can take O(n)

        return circular_list[0]

    # Recursive Solution with time complexity -> O(N) [ NeetCode Solution ]
    def findTheWinner(self, n: int, k: int) -> int:

        def helper(n, k):
            if n == 1:
                return 0

            return (helper(n-1, k) + k) % n

        return helper(n, k) + 1