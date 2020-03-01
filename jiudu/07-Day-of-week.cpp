#include "stdio.h"
#include "string.h"
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

/*
    这种类型的题目还需多加练习
    取模的地方有点小技巧，负数取模：(-1 % 7) = -1, (-8 % 7) = -1
*/

int dayOfMonth[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};

struct Date {
    int year;
    int month;
    int day;
    void nextDay() {
        day++;
        if (day > dayOfMonth[month][ISYEAP(year)]) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int buf[3001][13][32];

char monthName[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

char weekName[7][20] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

int main() {
    Date tmp;
    tmp.year = 0;
    tmp.month = 1;
    tmp.day = 1;
    int cnt = 0;
    while (tmp.year != 3001) {
        cnt++;
        buf[tmp.year][tmp.month][tmp.day] = cnt;
        tmp.nextDay();
    }
    int d, m, y;
    char s[20];
    while (scanf("%d%s%d", &d, s, &y) != EOF) {
        for (int i = 1; i <= 12; i ++ ) {
            if (strcmp(monthName[i], s) == 0) {
                m = i;
                break;
            }
        }
        int gapDays = buf[y][m][d] - buf[2020][2][24];
        /* if (gapDays >= 0) {
            printf("%s\n", weekName[((gapDays % 7) + 1)%7]);
        } else {
            int gapDays = 7 - ((-gapDays) % 7);
            printf("%s\n", weekName[(gapDays + 1)%7]);
        } */
        gapDays++;
        puts(weekName[(gapDays % 7 + 7) % 7]);
    }
}