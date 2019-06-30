#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> stock) {
    if (stock.size() <= 1) return 0;
    int Min = stock[0], ans = stock[1] - stock[0];
    for (int i = 1; i < stock.size(); i ++ ) {
        ans = max(stock[i] - Min, ans);
        Min = min(stock[i], Min);
    }
    return ans;
}