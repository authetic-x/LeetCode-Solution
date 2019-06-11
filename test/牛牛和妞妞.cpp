#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> flag(15, 4);
    int boy = 0, girl = 0;
    int m;
    for (int i = 0; i < 3; i ++ ) {
        cin >> m;
        flag[m]--;
        boy += m;
    }
    for (int i = 0; i < 3; i ++ ) {
        cin >> m;
        flag[m]--;
        girl += m;
    }
    int a[50];
    int cnt = 0;
    for (int i = 1; i <= 13; i ++ ) {
        for (int j = 0; j < flag[i]; j ++ ) {
            a[cnt++] = i;
        }
    }
    int winNum = 0, allNum = 0;
    for (int i = 0; i < cnt; i ++ ) {
        for (int j = 0; j < cnt; j ++ ) {
            if (i == j) continue;
            allNum++;
            if (boy+a[i] > girl + a[j]) winNum++;
        }
    }
    printf("%.4f\n", (double)winNum / (double)allNum);
}