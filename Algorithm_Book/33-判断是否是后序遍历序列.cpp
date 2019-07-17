#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() <= 1) return true;
        int len = sequence.size();
        int i = 0, root = sequence[len-1];
        while (i < len-1) {
            if (sequence[i] > root) break;
            i++;
        }
        int j = i;
        while (j < len-1) {
            if (sequence[j] < root) return false;
            j++;
        }
        vector<int> left, right;
        for (int k = 0; k < i; k ++ ) {
            left.push_back(sequence[k]);
        }
        for (int k = i; k < len-1; k ++ ) {
            right.push_back(sequence[k]);
        }
        return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
    }
};