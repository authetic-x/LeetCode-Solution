#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int m, n;
    vector<vector<char>>& v;
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) return false;
        m = board.size();
        n = board[0].size();
        v = board;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (board[i][j] == word[0]) {
                    if (dfs(0, i, j, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int k, int i, int j, string word) {
        if (i < 0 || i >= m || j < 0 || j >= n
            || v[i][j] != word[k]) return false;
        if (k == word.length()-1) return true;
        char cur = v[i][j];
        v[i][j] = '*';
        bool ans = dfs(k+1, i+1, j, word)
                    || dfs(k+1, i-1, j, word)
                    || dfs(k+1, i, j-1, word)
                    || dfs(k+1, i, j+1, word);
        v[i][j] = cur;
        return ans;
    }
};