#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 在长度为n-1的数组中存放着n-1个排序的数，其中数据范围为0-n-1，
 *        这n个数中，只有一个没有出现，找出这个数
 */

int GetMissNum(vector<int> v) {
    int st = 0, ed = v.size()-1;
    int mid = (st+ed)/2;
    while (st <= ed) {
        if (v[mid] != mid && (mid == 0 || v[mid-1] == mid-1)) {
            return mid;
        } else if (v[mid] != mid) {
            ed == mid-1;
        } else if (v[mid] == mid) {
            st = mid+1;
        }
        mid = (st+ed)/2;
    }
}