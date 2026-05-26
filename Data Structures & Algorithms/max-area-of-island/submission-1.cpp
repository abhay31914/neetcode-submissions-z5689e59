class Solution {
public:
    int R;
    int C;

    int dfs(vector<vector<int>>& grid, int i, int j){

        if(i < 0 || j < 0 || i >= R || j >= C || !grid[i][j]) return 0;

        grid[i][j] = 0;
        
        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);
        return 1 + up + down + right + left;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        R = grid.size();
        C = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i< R; i++){
            for(int j = 0; j< C; j++){

                if(grid[i][j]){
                    int area = dfs(grid, i, j);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
        
    }
};
