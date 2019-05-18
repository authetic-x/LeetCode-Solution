#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    Interval(): start(0), end(0) {}
    Interval(int st, int ed): start(st), end(ed) {}
};

/*
 *  Info: 给出一个interval数组，将重叠的intervals合并起来
 *  Key: 类似于PAT的排序类题目，定义一个Interval结构体，
 *       按照每个interval的开头排序，然后遍历添加即可
 */

// 未编译通过
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), 
                [](Interval a, Interval b){return a.start < b.start;});
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++ ) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};