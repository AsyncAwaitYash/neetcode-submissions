class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> mrow;
        unordered_map<int, unordered_set<char>> mcol;

        int subsize = 3;
        int row = 0, col = 0;

        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                if(!verifySubBox(row, col, mrow, mcol, board))
                    return false;
            }
        }

        return true;
    }

    bool verifySubBox(int row, int col,
        unordered_map<int, unordered_set<char>>& mrow,
        unordered_map<int, unordered_set<char>>& mcol,
        vector<vector<char>>& board)
    {
        unordered_set<char> subset;

        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                if (board[i][j] == '.')
                    continue;

                if(mrow[i].contains(board[i][j])){
                    return false;
                }

                if(mcol[j].contains(board[i][j])){
                    return false;
                }

                if(subset.contains(board[i][j])){
                    return false;
                }

                mrow[i].insert(board[i][j]);
                mcol[j].insert(board[i][j]);
                subset.insert(board[i][j]);
            }
        }

        return true;
    }
};
