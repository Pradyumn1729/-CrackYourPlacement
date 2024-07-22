class Solution {
public:
    vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
    
    bool isValid(int m, int n, int x, int y){
        return (x >= m || y>= n || x<0 || y < 0);
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>result(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count_live = 0;
                int count_dead = 0;

                for(auto vec : dir){
                    int x_ = vec[0] + i;
                    int y_ = vec[1] + j;

                    if(!isValid(m , n, x_, y_)){
                        if(board[x_][y_] == 1){
                            count_live++;
                        }else{
                            count_dead++;
                        }
                    }
                }
               if(board[i][j] == 0){
                    if(count_live == 3)
                        result[i][j] = 1;
                }else{
                    if(count_live < 2 || count_live > 3){
                        result[i][j] = 0;
                    }else if(count_live==2 || count_live == 3){
                        result[i][j] = 1;
                    }
                }
            }
        }

        board = result;
    }
};