class NumMatrix {
public:
    vector<vector<int>> V;

    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        V.resize(r, vector<int>(c, 0));

        for(int i = 0; i< r; i++){
            for(int j = 0; j < c; j++){
                V[i][j] = matrix[i][j];
            }
        }   
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = 0;

        for(int i = row1; i<= row2; i++){
            for(int j = col1; j<= col2; j++){
                sum += V[i][j];
            }
        }
        return sum;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */