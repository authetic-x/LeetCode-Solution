#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 经典的题目，面试重灾区
 *  Key: 两种做法
 *       1. partion, 保证第K个数左边的都比他小，右边的都比他大，时间复杂度O(n)
 *       2. 用一个数据结构存储K个数，一般是最大/最小堆，方便删除最大最小的那个数，
 *          程序直接用multiset，底层是红黑树
 */

vector<int> leastKnum(vector<int> v, int k) {
    multiset<int> s;
    if (v.size() <= k) return v;
    for (auto num : v) {
        s.insert(num);
        if (s.size() > k) {
            s.erase(s.begin());
        }
    }
    vector<int> ans;
    for (auto num : s) {
        ans.push_back(num);
    }
    return ans;
}