
/* Problem: 36. Valid Sudoku :Medium date:27/02/22 */


/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules. */



/* https://leetcode.com/problems/valid-sudoku/ */

// Time Complaxity: O(n^2)





#include <bits/stdc++.h>
using namespace std;

  bool isValidSudoku(vector<vector<char>>& board) {
          int row[9][9] = {0}, col[9][9] = {0}, cube[9][9] = {0};
            
    for(auto i=0; i<board.size(); i++)
    {
        for(auto j=0; j<board.size(); j++)
        {
            if(board[i][j] != '.')
            {
                int ch = board[i][j] - '0' - 1;
                int k = i/3 * 3 + j/3;
            
                if(row[i][ch]++ || col[j][ch]++ || cube[k][ch]++)
                    return false;
            }
            
        }
    }

    return true;
    }


int main()
{
	vector<vector<string>>v={{"8","3",".",".","7",".",".",".","."},
                  {"6",".",".","1","9","5",".",".","."},
                  {".","9","8",".",".",".",".","6","."},
                  {"8",".",".",".","6",".",".",".","3"},
                  {"4",".",".","8",".","3",".",".","1"},
                  {"7",".",".",".","2",".",".",".","6"},
                  {".","6",".",".",".",".","2","8","."},
                  {".",".",".","4","1","9",".",".","5"},
                  {".",".",".",".","8",".",".","7","9"}};
   
    cout<<isValidSudoku(v);
    
	return 0;
}

