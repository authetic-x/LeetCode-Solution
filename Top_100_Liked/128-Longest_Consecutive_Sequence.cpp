#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个整型数组，找出其中最长连续序列的包含数字的个数
 *  Key: 用set存储每个数字，从每个连续序列的第一个数字开始寻找，
 *       看似O(n*n)的时间复杂度实际上为O(n+n)，因为最坏情况下，
 *       数组本身是一个连续数组，则相当于将数组遍历了两次；
 *       不要看到求最大值问题就往DP上想，先看看有没有子问题，
 *       或者能不能用子问题求解！！！
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        int res = 0;
        for (auto num : nums) {
            if (s.find(num-1) == s.end()) {
                int current = 1;
                int n = num;
                while (s.find(n+1) != s.end()) {
                    n++;
                    current++;
                }
                res = max(res, current);
            }
        }
        return res;
    }
};