class Solution {
public:
    void dfs_iter(vector<vector<char>> &grid, int i, int j, int R, int C){

        if(i < 0 || j < 0 || i >= R || j >= C || grid[i][j] == '0') return;

        grid[i][j] = '0';

        dfs_iter(grid, i-1, j, R, C);
        dfs_iter(grid, i+1, j, R, C);
        dfs_iter(grid, i, j-1, R, C);
        dfs_iter(grid, i, j+1, R, C);
    
    }

    int numIslands(vector<vector<char>> &grid){

        int R = grid.size();
        if(R == 0) return 0;
        int C = grid[0].size();

        int result = 0;

        for(int i = 0; i< R; i++){
            for(int j = 0; j< C; j++){

                if(grid[i][j] =='1'){
                    dfs_iter(grid, i, j, R, C);
                    result +=1;
                }
            }
        }
        return result;
    }
};
