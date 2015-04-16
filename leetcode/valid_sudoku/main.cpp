#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
#define ROW_MASK 1
#define COL_MASK 2
#define BOX_MASK 4
            int use[9][9] = {0};
            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                {
                    if(board[i][j]!='.')
                    {
                        if((use[board[i][j]-'1'][i]&ROW_MASK) || (use[board[i][j]-'1'][j]&COL_MASK) || (use[board[i][j]-'1'][(i/3)*3+j/3]&BOX_MASK))
                        {
                            return false;
                        }
                        else
                        {
                            use[board[i][j]-'1'][i] |= ROW_MASK;
                            use[board[i][j]-'1'][j] |= COL_MASK;
                            use[board[i][j]-'1'][(i/3)*3+j/3] |= BOX_MASK;
                        }
                    }
                }
            }

            return true;
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    return 0;
}

