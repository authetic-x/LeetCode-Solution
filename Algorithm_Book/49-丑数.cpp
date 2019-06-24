#include <bits/stdc++.h>
using namespace std;

int GetUglyNum(int index) {
    int *v = new int[index];
    v[0] = 1;
    int nextIndex = 1;
    int *p2 = v, *p3 = v, *p5 = v;
    while (nextIndex < index) {
        v[nextIndex] = min(*p2*2, *p3*3, *p5*5);
        while(*p2 * 2 <= v[nextIndex]) {
            *p2++;
        }
        while(*p3 * 3 <= v[nextIndex]) {
            *p3++;
        }
        while (*p5 * 5 <= v[nextIndex]) {
            *p5++;
        }
        nextIndex++;
    }
    return v[index-1];
}