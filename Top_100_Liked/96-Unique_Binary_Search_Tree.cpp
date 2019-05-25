#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 求1-n的数能构成多少种不同的BST
 *  Key: DP。解决一个问题先试着抽象出一种特殊情况，
 *       对于一道有难度且陌生的题，没人能一上来就写代码！
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res[0] = 1;
        for (int i = 1; i <= n; i ++ ) {
            res[1] = 0;
            if (i <= 2) {
                res[i] = i;
            } else {
                for (int j = 1; j <= i; j ++ ) {
                    res[i] += res[j-1]*res[i-j];
                }
            }
        }
        return res[n];
    }
};