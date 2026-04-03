class Solution {
public:
    bool is_valid(const vector<vector<int>>& grid, int dx, int dy){
    int R = grid.size();
    int C = grid[0].size();

    if(dx > -1 && dx < R && dy > -1 && dy < C && grid[dx][dy] == 1) return true;

    return false;
}

int count_time(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& fresh_count){

    int minutes = 0;

    vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    while(!q.empty() && fresh_count){

        int q_size = q.size();
        minutes++;

        while(q_size--){
            pair<int, int> temp = q.front();
            q.pop();

            for(int i = 0; i< 4; i++){

                int dx = temp.first + d[i].first;
                int dy = temp.second + d[i].second;

                if(is_valid(grid, dx, dy)){
                    grid[dx][dy] = 2;
                    q.push({dx, dy});
                    fresh_count--;
                }
            }
        }
    }

    return fresh_count == 0? minutes : -1;

}

int orangesRotting(vector<vector<int>>& grid){

    int R = grid.size();
    if(R == 0) return -1;
    int C = grid[0].size();

    int fresh_count = 0;
    queue<pair<int, int>> q;


    for(int i= 0; i< R; i++){
        for(int j = 0; j< C; j++){

            if(grid[i][j] == 1) fresh_count++;

            else if(grid[i][j] == 2) q.push({i, j});
        }
    }

    if(fresh_count == 0) return 0;
    if(q.empty())return -1;

    return count_time(grid, q, fresh_count);
}
};
