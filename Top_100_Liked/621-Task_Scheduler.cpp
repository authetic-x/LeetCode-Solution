#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 模拟CPU调度任务，求interval数量
 *  Key: 一开始做麻烦了，排序是一种方法，
 *       可以用优先队列
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int book[26] = {0};
        for (auto ch : tasks) {
            book[ch-'A']++;
        }
        sort(book, book+26);
        int time = 0;
        while (book[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (book[25] == 0) break;
                if (i < 26 && book[25-i] >= 0) {
                    book[25-i]++;
                }
                time++;
                i++;
            }
            sort(book, book+26);
        }
        return time;
    }
};

class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>, greater<int>> q;
        
    }
};