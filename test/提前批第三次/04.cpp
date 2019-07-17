#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i ++ ) {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = 0; i < n; i ++ ) {
        int j = 0;
        for (j = 0; j < n; j ++ ) {
            int a = v[i][0], b = v[i][1];
            if (a != v[i][0] && b != v[i][1]) break;
        }
        if (j == n) {
            cout << v[i][0] << " " << v[i][1] << endl;
            break;
        }
    }
    return 0;
}