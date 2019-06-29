#include <bits/stdc++.h>
using namespace std;

/*
 *  先想办法把出现一次的数字分到两个数组中，方法是用0异或数组所有数，
 *  结果肯定是那两个数的异或结果，找到结果中二进制的第一个1，根据这一位
 *  是否为1进行划分，相同数字肯定被分到同一组，最后对两个数组分别异或即可！
 */

vector<int> ApearOnlyOnce(vector<int> v) {
    vector<int> ans;
    if (v.size() <= 1) return ans;

    int tmp = 0;
    for (auto num : v) {
        tmp ^= num;
    }
    int indexOfOne = 1;
    while (tmp & 1 == 0) {
        tmp >> 1;
        indexOfOne << 1;
    }
    vector<int> v1, v2;
    for (auto num : v) {
        if (num & indexOfOne == 1) {
            v1.push_back(num);
        } else {
            v2.push_back(num);
        }
    }
    tmp = 0;
    for (auto num : v1) {
        tmp ^= num;
    }
    ans.push_back(tmp);
    tmp = 0;
    for (auto num : v2) {
        tmp ^= num;
    }
    ans.push_back(tmp);
    return ans;
}