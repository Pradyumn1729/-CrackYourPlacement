class Solution {
public:
    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    bool find(int i, int j, vector<vector<char>>& board, string &word, int idx){
        if(idx == word.length())
            return true;
        
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$')
            return false;

        if(board[i][j] != word[idx])
            return false;

        char temp = board[i][j];

        board[i][j] = '$';

        for(auto &vec : dir){
            int x_ = i + vec[0];
            int y_ = j + vec[1];

            if(find(x_, y_, board, word, idx+1)){
                return true;
            }
        }
        board[i][j] = temp;
        
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        int len = word.length();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0] && find(i, j, board, word, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};