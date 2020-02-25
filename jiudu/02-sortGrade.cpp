#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;

struct Student {
    char name[101];
    int age;
    int grade;
};

bool cmp(Student a, Student b) {
    if (a.grade != b.grade) {
        return a.grade > b.grade;
    } else if (strcmp(a.name, b.name) != 0) {
        return strcmp(a.name, b.name) < 0;
    } else {
        return a.age < b.age;
    }
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        Student *stus = (Student *)malloc(n * sizeof(Student));
        for (int i = 0; i < n; i ++ ) {
            scanf("%s%d%d", stus[i].name, &stus[i].age, &stus[i].grade);
        }
        sort(stus, stus + n, cmp);
        for (int i = 0; i < n; i ++ ) {
            printf("%s %d %d\n", stus[i].name, stus[i].age, stus[i].grade);
        }
    }
    return 0;
}