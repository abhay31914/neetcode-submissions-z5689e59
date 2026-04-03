class Solution {
public:
    void dfs_iter(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j, int R, int C){

        if(i < 0 || j < 0 || i >= R || j >= C || visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        dfs_iter(grid, visited, i-1, j, R, C);
        dfs_iter(grid, visited, i+1, j, R, C);
        dfs_iter(grid, visited, i, j-1, R, C);
        dfs_iter(grid, visited, i, j+1, R, C);
    
    }

    int numIslands(vector<vector<char>> &grid){

        int R = grid.size();
        if(R == 0) return 0;
        int C = grid[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int result = 0;

        for(int i = 0; i< R; i++){
            for(int j = 0; j< C; j++){

                if(grid[i][j] =='1' && !visited[i][j]){
                    dfs_iter(grid, visited, i, j, R, C);
                    result +=1;
                }
            }
        }
        return result;
    }
};
