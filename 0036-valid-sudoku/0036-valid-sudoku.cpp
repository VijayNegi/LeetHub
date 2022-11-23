class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> rows(9),cols(9),boxes(9);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                int num = board[i][j]-'1';
                if(rows[i].test(num))
                    return false;
                rows[i].set(num);
                if(cols[j].test(num))
                    return false;
                cols[j].set(num);
                int b = (i/3)*3 + (j/3);
                if(boxes[b].test(num))
                    return false;
                boxes[b].set(num);
            }
        }
        return true;
    }
};