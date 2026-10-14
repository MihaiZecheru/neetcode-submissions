class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<char>> seen_in_col(n);
        std::vector<std::vector<std::unordered_set<char>>> seen_in_subsquare(
            n / 3, 
            std::vector<std::unordered_set<char>>(n / 3)
        );

        for (int i = 0; i < n; ++i)
        {
            unordered_set<char> seen_in_row = {};
            for (int j = 0; j < n; ++j)
            {
                // Handle row
                auto [_, inserted_1] = seen_in_row.insert(board[i][j]);
                if (!inserted_1 && board[i][j] != '.') return false;

                // Handle col
                auto [_, inserted_2] = seen_in_col[j].insert(board[i][j]);
                if (!inserted_2 && board[i][j] != '.') return false;

                // Handle subsquare
                auto [_, inserted_3] = seen_in_subsquare[i / 3][j / 3].insert(board[i][j]);
                if (!inserted_3 && board[i][j] != '.') return false;
            }
        }

        return true;
    }
};
