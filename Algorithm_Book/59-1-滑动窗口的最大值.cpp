#include <bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> num, int k) {
    vector<int> ans;
    if (num.size() >= k && k >= 1) {
        deque<int> index;
        for (int i = 0; i < k; i ++ ) {
            while (!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }
        for (int i = k; i < num.size(); i ++ ) {
            ans.push_back(index.front());
            while (!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            if (!index.empty() && index.front() <= i-k) {
                index.pop_front();
            }
            index.push_back(i);
        }
        ans.push_back(index.front());
    }
    return ans;
}