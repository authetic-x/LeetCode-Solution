#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 在一个每行和每列都排好序的二维数组里找目标值
 *  Key: 从数组右上角出发，每次可排除掉一列或一行
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};