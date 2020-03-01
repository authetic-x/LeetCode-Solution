#include "stdio.h"
#include "algorithm"
using namespace std;

struct Program {
    int startTime;
    int endTime;
} buf[100];

bool cmp(Program a, Program b) {
    return a.endTime < b.endTime;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
        }
        sort(buf, buf + n, cmp);
        int currentTime = 0, ans = 0;
        for (int i = 0; i < n; i ++ ) {
            if (currentTime <= buf[i].startTime) {
                ans++;
                currentTime = buf[i].endTime;
            }
        }
        printf("%d\n", ans);
    }
}