class Solution {
public:
    bool isRow(vector<vector<char>>& board, int row, char k){
        for(int j = 0; j < 9; j++){
            if(board[row][j] == k) return false;
        }
        return true;
    }

    bool isColumn(vector<vector<char>>& board, int col, char k){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == k) return false;
        }
        return true;
    }

    bool isBox(vector<vector<char>>& board, int startRow, int startCol, char k){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[startRow + i][startCol + j] == k) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char num = board[i][j];
                if(num == '.') continue; 
                board[i][j] = '.';

                if(!isRow(board, i, num) || 
                   !isColumn(board, j, num) || 
                   !isBox(board, i - i % 3, j - j % 3, num)){
                    return false;
                }

                board[i][j] = num;
            }
        }
        return true;
    }
};
