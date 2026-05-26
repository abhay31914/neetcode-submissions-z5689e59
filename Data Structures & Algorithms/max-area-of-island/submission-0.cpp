class Solution {
public:
    int R;
    int C;

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){

        if(i < 0 || j < 0 || i >= R || j >= C || visited[i][j] || !grid[i][j]) return 0;

        visited[i][j] = true;
        
        int up = dfs(grid, i-1, j, visited);
        int down = dfs(grid, i+1, j, visited);
        int left = dfs(grid, i, j-1, visited);
        int right = dfs(grid, i, j+1, visited);

        return 1 + up + down + right + left;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        R = grid.size();
        C = grid[0].size();

        int maxArea = 0;

        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for(int i = 0; i< R; i++){
            for(int j = 0; j< C; j++){

                if(grid[i][j] && !visited[i][j]){
                    int area = dfs(grid, i, j, visited);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
        
    }
};
