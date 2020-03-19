#include "stdio.h"
#include "string"
#include "map"
using namespace std;

/*
    类似于拓扑排序，只不过更简单，
    判断是否只有一个节点的入度为1
*/

// 入度
int in[2001];
map<string, int> mp;

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        char str1[50], str2[50];
        for (int i = 0; i < 2001; i ++ ) in[i] = 0;
        mp.clear();
        int idx = 0;
        for (int i = 0; i < n; i ++ ) {
            scanf("%s%s", str1, str2);
            string a = str1, b = str2;
            if (mp.find(a) == mp.end()) {
                mp[a] = idx++;
            }
            int idx_tmp;
            if (mp.find(b) == mp.end()) {
                idx_tmp = idx;
                mp[b] = idx++;
            } else {
                idx_tmp = mp[b];
            }
            in[idx_tmp]++;
        }
        int cnt = 0;
        for (int i = 0; i < idx; i ++ ) {
            if (in[i] == 0) cnt++;
        }
        puts(cnt == 1 ? "Yes" : "No");
    }
    return 0;
}