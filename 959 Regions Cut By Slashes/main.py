class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
            rows1, cols1 = len(grid), len(grid[0])
            rows2, cols2 = 3 * rows1 , 3 * cols1
            grid2 = [[0] * cols2 for _ in range(rows2)]


            # Scaling grid to 3X, 3X
            for r in range(rows1):
                for c in range(cols1):
                    r2, c2 = r * 3, c * 3
                    if grid[r][c] == "/":
                        grid2[r2][c2 + 2] = 1
                        grid2[r2 + 1][c2 + 1] = 1
                        grid2[r2 + 2][c2] = 1

                    elif grid[r][c] == "\\":
                        grid2[r2][c2] = 1
                        grid2[r2 + 1][c2 + 1] = 1
                        grid2[r2 + 2][c2 + 2] = 1

            def dfs(r, c, visit):
                if (r < 0 or c < 0 or r == rows2 or c == cols2 or grid2[r][c] != 0 or (r, c) in visit):
                    return 

                visit.add((r, c))
                neighbors = [[r-1, c], [r+1, c], [r, c+1], [r, c-1]]
                for nr, nc in neighbors:
                    dfs(nr, nc, visit)

            visit = set()
            res = 0

            for r in range(rows2):
                for c in range(cols2):
                        if grid2[r][c] == 0 and (r, c) not in visit:
                            dfs(r, c, visit)
                            res += 1 

            return res
