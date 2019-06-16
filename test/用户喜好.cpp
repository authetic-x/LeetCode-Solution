#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) {
        int k;
        cin >> k;
        mp[k].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        vector<int> tmp = mp[k];
        int cnt = 0;
        for (auto num : tmp) {
            if (num >= l && num <= r) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}