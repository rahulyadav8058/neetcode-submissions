class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int ind, int i, int j) {
        if (ind == word.size()) return true;
        if (board[i][j] == word[ind]) {
            char temp = board[i][j];
            board[i][j] = '#';
            vector<int> x = {1, -1, 0, 0}, y = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++) {
                int nx = i + x[k];
                int ny = j + y[k];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                    if (dfs(board, word, ind + 1, nx, ny)) {
                        board[i][j] = temp;
                        return true;
                    }
                }
            }
            board[i][j] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0])

                    {
                        if(word.size()==1)return true;
                        if (dfs(board, word, 0, i, j)) return true;}
                
            }
        }

        return false;
    }
};
