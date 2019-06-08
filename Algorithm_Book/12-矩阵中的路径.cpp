#include <bits/stdc++.h>
using namespace std;

/*
 *  判断一个字符矩阵中是否存在某个单词的路径
 *  回溯，依据leetcode原题印象写的
 */

bool hasPath(vector<string> matrix, string word) {
    if (word.length() == 0) return true;
    if (matrix.size() == 0) return false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i ++ ) {
        for (int j = 0; j < cols; j ++ ) {
            if (Core(matrix, word, j, i, 0, rows, cols)) {
                return true;
            }
        }
    }
    return false;
}

bool Core(vector<string> &matrix, string &word, int col, int row, int k,
            int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || 
        matrix[row][col] != word[k]) return false;
    if (k == word.length()-1) return true;
    char tmp = matrix[row][col];
    matrix[row][col] = '*';
    bool res = Core(matrix, word, col+1, row, k+1, rows, cols)
                || Core(matrix, word, col-1, row, k+1, rows, cols)
                || Core(matrix, word, col, row-1, k+1, rows, cols)
                || Core(matrix, word, col, row+1, k+1, rows, cols);
    matrix[row][col] = tmp;
    return res;
}