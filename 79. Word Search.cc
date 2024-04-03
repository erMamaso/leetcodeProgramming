class Solution {
public:
    bool solver(vector<vector<char>>& board, vector<vector<bool>>& bboard, string word, int idx, int i, int j){
        if(bboard[i][j]) return false; //If we are in an already used cell then it is false.
        
        bool up, down, left, right;
        up = down = left = right = false; //Let's check all 4 neighbours

        if(board[i][j] == word[idx]){
            bboard[i][j] = true; // We mark this cell as visited
            if(idx+1 == word.size()) return true; // If we were in the last letter and we found it, then it is true. Useful for case 87 [["a"]]
            
            // Let's visit all neighbours
            if(i > 0)                   up    = solver(board, bboard, word, idx+1, i-1, j);
            if(i < board.size()-1)      down  = solver(board, bboard, word, idx+1, i+1, j);
            if(j > 0)                   left  = solver(board, bboard, word, idx+1, i, j-1);
            if(j < board[0].size()-1)   right = solver(board, bboard, word, idx+1, i, j+1);
            
            bboard[i][j] = false; // We need to unmark this cell as visited for next iterations
        }

        return up || down || left || right; //If we just found at least one then it is true.
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> bboard(board.size(), vector<bool>(board[0].size(), false));
        //We will iterate for the whole board 0 <= i <= board.size(), 0 <= j <= board[0].size()
        for(int i = 0; i < board.size(); ++i) for(int j = 0; j<board[0].size(); ++j) if(solver(board, bboard, word, 0, i, j)) return true;
        return false;
    }
};