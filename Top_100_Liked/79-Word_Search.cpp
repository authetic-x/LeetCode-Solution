#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个由字符组成的二维数组和一个字符串，判断从数组中任意
 *        一个位置开始通过上下左右移动，能够构成字符串
 *  Key: 深度优先或者广度优先，题目本身不难，但要多写，
 *       注意并不一定要用标记数组，下面添加字符的做法就很巧妙！
 */


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) return true;

        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, 
             int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n 
            || word[k] != board[i][j]) return false;
        if (k == word.length()-1) return true;

        int cur = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(board, word, k+1, i+1, j)
                    || dfs(board, word, k+1, i-1, j)
                    || dfs(board, word, k+1, i, j+1)
                    || dfs(board, word, k+1, i, j-1);
        board[i][j] = '*';
        return ans;
    }
};