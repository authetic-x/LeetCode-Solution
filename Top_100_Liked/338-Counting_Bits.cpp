#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 计算0~num之间的所有整数中，每个整数二进制包含1的个数
 *  Key： 可以利用前面计算的结果，如5 = 1+ans[5-4]
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        if (num >= 0) ans.push_back(0);
        if (num >= 1) ans.push_back(1);
        if (num >= 2) ans.push_back(1);
        int i = 3, tmp = 2;
        while (i <= num) {
            if (i == tmp*2) {
                ans.push_back(1);
                tmp = tmp*2;
            } else {
                ans.push_back(1+ans[i-tmp]);
            }
            i++;
        }
        return ans;
    }
};