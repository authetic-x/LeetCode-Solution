#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;

int countNum = 0;
bool visited[maxn][maxn]{false};

/*
    bool *visited = new bool[rows*cols];
    for (int i = 0; i < rows*cols; i ++ ) {
        visited[i] = false;
    }
    ...
    delete[] visited;
 */


int movingCount(int k, int rows, int cols) {
    if (k < 0) return 0;
    recursive(0, 0, rows, cols, k);
    return countNum;
}

void recursive(int row, int col, int rows, int cols, int k) {
    if (DigitSum(row, col) > k) return;
    if (row >= rows || col >= cols) return;
    if (!visited[row][col]) {
        visited[row][col] = true;
        countNum++;
        recursive(row+1, col, rows, cols, k);
        recursive(row, col+1, rows, cols, k);
    }
}

int DigitSum(int a, int b) {
    int sum = 0;
    while (a != 0) {
        sum += a % 10;
        a = a/10;
    }
    while (b != 0) {
        sum += b % 10;
        b = b / 10;
    }
    return sum;
}