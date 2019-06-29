#include <bits/stdc++.h>
using namespace std;

/*
 *  由于其它数字都出现了三次，将所有数字的每一位加起来，能被3整除说明
 *  目标数字的那一位为0，否则为1
 */

int appearOnlyOnce(vector<int> v) {
    if (v.size() == 0) return 0;
    int bitMask[32]{0};
    for (auto num : v) {
        for (int i = 31; i >= 0; i -- ) {
            bitMask[i] += (num & 1);
            num >> 1;
        }
    }
    int ans = 0;
    for (auto num : bitMask) {
        ans << 1;
        ans += (num % 3);
    }
}