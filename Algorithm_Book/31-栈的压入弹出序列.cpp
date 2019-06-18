#include <bits/stdc++.h>
using namespace std;

bool isPopOrder(vector<int> pu, vector<int> po) {
    stack<int> st;
    int i = 0, j = 0;
    bool ans = true;
    while (j < po.size()) {
        while (st.empty() || st.top() != po[j]) {
            if (i == pu.size()) break;
            st.push(pu[i++]);
        }
        if (st.top() != po[j] && i == pu.size()) {
            ans = false;
            break;
        }
        st.pop();
        j ++;
    }
    return ans;
}