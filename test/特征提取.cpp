#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

int a[maxn][maxn];
int flag[maxn][maxn];

// YES!!!
int main() {
    int n;
    cin >> n;
    while (n--) {
        std::fill (a, a+maxn*maxn, 0);
        std::fill(flag, flag+maxn*maxn, 0);
        int res = 0;
        int m;
        cin >> m;
        for (int i = 1; i <= m; i ++ ) {
            int k;
            cin >> k;
            int x, y;
            if (k == 0) {
                a[x][y] = 0;
                flag[x][y] = 0;
            }
            for (int j = 0; j < k; j ++ ) {
                cin >> x >> y;
                if (a[x][y] == 0) {
                    a[x][y] = i;
                    flag[x][y] = i;
                    res = max(res, 1);
                } else if (flag[x][y] == i-1) {
                    flag[x][y] = i;
                    res = max(res, i-a[x][y]+1);
                } else {
                    a[x][y] = i;
                    flag[x][y] = i;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}