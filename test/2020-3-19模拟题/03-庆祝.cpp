#include "stdio.h"
#include "math.h"
#include "algorithm"
using namespace std;

int list[21];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &list[i]);
        }
        sort(list, list+n);

        int tmp[60] = {-1};
        int x = 29, y = 31;
        tmp[30] = list[0];
        bool left = true;
        int ans = 0;
        for (int i = 1; i < n; i ++ ) {
            if (left) {
                tmp[x] = list[i];
                ans = max(ans, abs(tmp[x] - tmp[x+1]));
                if (tmp[y-1] != -1) {
                    ans = max(ans, abs(tmp[x] - tmp[y-1]));
                }
                x--;
                left = !left;
            } else {
                tmp[y] = list[i];
                ans = max(ans, abs(tmp[y] - tmp[y-1]));
                if (tmp[x+1] != -1) {
                    ans = max(ans, abs(tmp[y] - tmp[x+1]));
                }
                y++;
                left = !left;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}