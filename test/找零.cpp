#include <bits/stdc++.h>
using namespace std;

// 可以用01背包

int main() {
    int n;
    cin >> n;
    int remain =1024 - n;
    int cnt = 0;
    while (remain >= 64) {
        cnt += remain/64;
        remain %= 64;
    }
    while (remain >= 16) {
        cnt += remain / 16;
        remain %= 16;
    }
    while (remain >= 4) {
        cnt += remain / 4;
        remain %= 4;
    }
    cnt += remain;
    cout << cnt << endl;
    return 0;
}