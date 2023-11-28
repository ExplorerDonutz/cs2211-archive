#include <stdio.h>

int day_of_year(int month, int day, int year) {
    int days = day;

    for (int i = 0; i < month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 2:
                if (year % 400 == 0 || (year % 4 == 0 && !year % 100 == 0))
                    days += 29;
                else
                    days += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
        }
    }

    return days;
}

int main(void) {
    int d, m, y;
    scanf("%d%d%d", &m, &d, &y);

    printf("%d\n", day_of_year(m, d, y));
    return 0;
}
