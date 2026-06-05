class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || grid[r][c] == -1){
            return 0;
        }
        grid[r][c] = -1;
        int sum = dfs(grid, r - 1, c);
        sum += dfs(grid, r + 1, c);
        sum += dfs(grid, r, c - 1);
        sum += dfs(grid, r, c + 1);
        return 1 + sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    m = max(m, dfs(grid, r, c));
                }
            }
        }
        return m;
    }
};
