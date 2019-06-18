#include <bits/stdc++.h>
using namespace std;

void PrintMatrix(vector<vector<int>> matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();
    int top = 0, bottom = m-1, left = 0, right = n-1;
    int i = 0, j = 0;
    while (top < bottom && left < right) {
        while (j < right) {
            printf("%d ", matrix[i][j]);
            j ++;
        }
        while (i < bottom) {
            printf("%d ", matrix[i][j]);
            i ++;
        }
        while (j > 0) {
            printf("%d ", matrix[i][j]);
            j --;
        }
        while (i > 0) {
            printf("%d ", matrix[i][j]);
            i --;
        }
        i ++, j ++;
        top ++, left++, bottom--, right--;
    }
    if (top == bottom && left == right) {
        printf("%d ", matrix[i][j]);
    }
    if (top == bottom) {
        while (j <= right) {
            printf("%d ", matrix[i][j]);
            j ++;
        }
    }
    if (left == right) {
        while (i <= bottom) {
            printf("%d ", matrix[i][j]);
            i ++;
        }
    }
}