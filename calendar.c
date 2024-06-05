#include <stdio.h>

// 判断是否是闰年
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// 获取某个月份的天数
int getDaysInMonth(int year, int month) {
    int days;
    switch(month) {
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = isLeapYear(year) ? 29 : 28;
            break;
        default:
            days = 31;
            break;
    }
    return days;
}

// 获取某一天是星期几
int getDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int century = year / 100;
    year %= 100;
    int weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + century * 2) % 7;
    return weekday;
}

// 打印日历
void printCalendar(int year, int month) {
    printf("      %d年%d月\n", year, month);
    printf("日 一 二 三 四 五 六\n");
    
    int daysInMonth = getDaysInMonth(year, month);
    int dayOfWeek = getDayOfWeek(year, month, 1);
    
    for (int i = 0; i < dayOfWeek; i++) {
        printf("   ");
    }
    
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((day + dayOfWeek) % 7 == 0 || day == daysInMonth) {
            printf("\n");
        }
    }
}

int main() {
    int year, month;
    
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    
    printCalendar(year, month);
    
    return 0;
}
