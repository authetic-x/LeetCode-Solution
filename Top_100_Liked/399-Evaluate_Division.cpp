#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 图问题，有点小难，可以用并查集
 *  Key: 
 */

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                vector<double>& values, vector<vector<string>>& queries) {
        int father[30];
        for (int i = 0; i < 30; i ++ ) father[i] = i;
        for (int i = 0; i < equations.size(); i ++ ) {
            vector<string> str = equations[i];
            int p = str[0][0] - 'a', q = str[1][0]-'a';
            graph[p][q] = values[i];
            
        }
    }
private:
    int graph[30][30] = {0};
    
};