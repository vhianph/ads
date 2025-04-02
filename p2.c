#include <stdio.h>
#include <math.h>

typedef struct {
    int month;
    int day;
} Date;

Date initDate(int month, int day) {
    Date d;
    d.month = month; // valid values: 1 to 12
    d.day = day;  // valid values: 1 to 31 (depending on the month)
    return d;
}

void nextDay(Date *d) {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d->day < daysInMonth[d->month]) {
        d->day++;
    } else {
        d->day = 1;
        if (d->month < 12)
            d->month++;
        else
            d->month = 1;
    }
}

int dayOfYear(Date d) {
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    for (int i = 1; i < d.month; i++) {
        total += daysInMonth[i];
    }
    total += d.day;
    return total;
}

int dateDifference(Date d1, Date d2) {
    int day1 = dayOfYear(d1);
    int day2 = dayOfYear(d2);
    int diff = day1 - day2;
    return diff < 0 ? -diff : diff;
}

void displayDate(Date d) {
    printf("Month: %d, Day: %d\n", d.month, d.day);
}

int main() {
    Date date1 = initDate(3, 14); // March 14
    Date date2 = initDate(4, 10); // April 10

    displayDate(date1);
    displayDate(date2);

    nextDay(&date1);
    displayDate(date1);

    int diff = dateDifference(date1, date2);
    printf("Difference: %d day(s)\n", diff);

    /* Complexity:
       nextDay: O(1)
       dayOfYear and dateDifference: O(1) (constant time, as the number of months is fixed)
    */
    
    return 0;
}
