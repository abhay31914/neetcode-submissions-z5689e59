class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int sizeRows = grid.size();
        int sizeCol = grid[0].size();
        int perimeter = 0;

        for(int i = 0; i< sizeRows; i++){
            for(int j = 0; j< sizeCol; j++){

                if(grid[i][j] == 1){
                    perimeter += 4;

                    if(i > 0 && grid[i-1][j] == 1){
                        perimeter -= 2;
                    }

                    if(j > 0 && grid[i][j-1] == 1){
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;        
    }
};