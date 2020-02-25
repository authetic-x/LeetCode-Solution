#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;

struct Student {
    char no[10];
    char name[100];
    char age;
    char sex[5];
}buf[1000];

bool cmp(Student a, Student b) {
    return strcmp(a.no, b.no) ? 1 : 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int m;
        for (int i = 0; i < n; i ++ ) {
            scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
        }
        sort(buf, buf + n, cmp);
        int left = 0, right = n - 1;
        scanf("%d", &m);
        int res = -1;
        while (m--) {
            char x[10];
            scanf("%s", x);
            while (left <= right) {
                int mid = (left + right) / 2;
                int tmp = strcmp(x, buf[mid].no);
                if (tmp == 0) {
                    res = mid;
                    break;
                }else if (tmp < 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            if (res == -1) {
                printf("No Answer\n");
            } else {
                printf("%s %s %s %d\n", buf[res].no, buf[res].name, buf[res].sex, buf[res].age);
            }
        }
    }
    return 0;
}