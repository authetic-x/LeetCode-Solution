#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[14] = {0};
    vector<int> res;
    for (int i = 0; i < 13; i ++ ) {
        int m;
        cin >> m;
        a[m]++;
    }
    int remain[26];
    int cnt = 0;
    for (int i = 1; i <= 13; i ++) {
        for (int j = 0; j < 4-a[i]; j ++ ) {
            remain[cnt++] = i;
        }
    }
    int tmp[14];
    for (int i = 1; i <= 13; i ++) tmp[i] = a[i];
    int flag = 0;
    // 先判断有没有刻子
    for (int i = 1; i <= 13; i ++ ) {
        if (a[i] >= 3) {
            a[i] -= 3;
            flag ++;
        } 
        if (flag == 3) break;
    }
    if (flag == 3) {
        for (int i = 1; i <= 13; i ++) {
            if (a[i] != 0) {
                if (a[i] == 2) {
                    for (int j = i+1; j <= 13; j ++ ) {
                        if (a[j] == 2) {
                            res.push_back(i);
                            res.push_back(j);
                            break;
                        }
                    }
                } else if (a[i] == 1) {
                    for (int j = i+1; j <= 13; j ++ ) {
                        if (a[j] == 3) {
                            res.push_back(i);
                            break;
                        }
                    }
                } else if (a[i] == 3) {
                    for (int j = i+1; j <= 13; j ++ ) {
                        if (a[j] == 1) {
                            res.push_back(j);
                            break;
                        }
                    }
                }
            }
        }
    }
    flag = 0;
    for (int i = 1; i <= 13; i ++ ) a[i] = tmp[i];
    // 在判断又没有顺子
    for (int j = 0; j < 3; j ++ ) {
        for (int i = 1; i<= 11; i ++ ) {
            if (a[i] > 0 && a[i+1] > 0 && a[i+2] > 0) {
                a[i] -- , a[i+1] -- , a[i+2] --;
            }
            if (flag == 3) break;
        }
    }
    if (flag == 3) {
        for (int i = 1; i <= 13; i ++ ) {
            if (a[i] > 0 && a[i+1] > 0 && a[i+2] > 0) {
                a[i] -- , a[i+1] -- , a[i+2] --;
                for (int j = 1; j <= 13; j ++ ) {
                    if (a[j] != 0) {
                        res.push_back(j);
                        break;
                    }
                }
                flag = 0;
                break;
            }
        }
        if (!flag) {
            for (int i = 1; i <= 13; i ++ ) {
                if (a[i] >= 2) {
                    a[i] -= 2;
                    for (int j = 1; j <= 12; j ++ ) {
                        if (a[j] > 0 && a[j+1] > 0) {
                            if (j == 1) res.push_back(i+2);
                            else if (j == 12) res.push_back(i-1);
                            else {
                                res.push_back(i-1);
                                res.push_back(i+2);
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}