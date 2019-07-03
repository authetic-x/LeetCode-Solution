#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 重新排队
 *  Key: 下面是参考 Liu Chuo 同学的做法，先按身高，人数排序
 *       然后直接将每个人根据他前面的位置移动到res对应的位置，
 *       位置被占自动后移，就是结果！
 */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if (people.size() == 0) return res;
        auto cmp = [](vector<int> a, vector<int> b) {
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        };
        sort(people.begin(), people.end(), cmp);
        for (auto it : people) {
            res.insert(res.begin()+it[1], it);
        }
        return res;
    }
};