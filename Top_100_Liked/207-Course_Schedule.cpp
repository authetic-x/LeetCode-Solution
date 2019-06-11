#include <bits/stdc++.h>
using namespace std;

/*
    Info: 先修课问题，给出课程之间的关系，判断能否完成所有课程
    Key: 实际上等于判断图中是否存在环。先用邻接表建立图，然后计算
         出所有结点的入度，遍历n次，n为结点个数，每次寻找一个入度为零
         的结点，找不到返回false，找到后将该结点入度置为-1，并将它出度
         中的所有结点的入度减一，如果图中不存在环，应该会正常返回true。
         据说这是拓扑排序！！
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = createGraph(numCourses, prerequisites);
        vector<int> Indegree = computeDegree(g);
        for (int i = 0; i < numCourses; i ++ ) {
            int j = 0;
            for (; j < numCourses; j ++ ) {
                if (!Indegree[j]) {
                    break;
                }
            }
            if (j == numCourses) return false;
            Indegree[j] --;
            for (auto v : g[j]) {
                Indegree[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    graph createGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (auto pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
        }
        return g;
    }
    vector<int> computeDegree(graph &g) {
        vector<int> Indegree(g.size(), 0);
        for (auto p : g) {
            for (auto v : p) {
                Indegree[v]++;
            }
        }
        return Indegree;
    }
};