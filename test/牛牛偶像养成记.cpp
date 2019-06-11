#include <bits/stdc++.h>
using namespace std;

struct Node {
    int st, ed;
};

const int maxn = 100005;

struct Node node[maxn];

bool cmp(Node a, Node b) {
    if (a.ed != b.ed) {
        return a.ed < b.ed;
    } else {
        return a.st < b.st;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int m;
        cin >> node[i].st >> m;
        node[i].ed = node[i].st + m;
    }
    sort(node, node+n, cmp);
    int ans = 0, timeNow = 0;
    for (int i = 0; i < n; i ++ ) {
        if (timeNow <= node[i].st) {
            ans ++;
            timeNow = node[i].ed;
        }
    }
    cout << ans << endl;
    return 0;
}