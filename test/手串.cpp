#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i ++ ) {
        int num;
        cin >> num;
        int tmp;
        for (int j = 0; j < num; j ++ ) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    int cnt = 0;
    bool visit[c+1] = {false};
    for (int i = 0; i < n; i ++ ) {
        int color[c+1] = {0};
        for (int j = 1; j < m; j ++ ) {
            int num_i = (i+j)%n;
            for (auto col : v[num_i]) {
                if (color[col] == 1 && !visit[col]) {
                    visit[col] = true;
                    cnt++;
                } else {
                    color[col] = 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}