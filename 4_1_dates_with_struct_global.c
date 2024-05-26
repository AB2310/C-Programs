#include<stdio.h>

struct Date
{
    int day, month, year;
};

struct Date date1,date2;

void readDates() {

    printf("Enter date1 (DD/MM/YYYY) : ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);
    printf("Enter date2 (DD/MM/YYYY) : ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);
}

void printDates() {

    printf("Date 1 : ");
    printf("%2d/%2d/%2d\n", date1.day, date1.month, date1.year);
    printf("Date 2 : ");
    printf("%2d/%2d/%2d\n", date2.day, date2.month, date2.year);
    
}
int isDatesEqual(struct Date date1, struct Date date2)
{
    return (date1.day == date1.day && date1.month == date2.month && date2.year == date2.year);
}
int main() {

    

    readDates();
//    readDate(&d2);

    printDates();
//    printDate(d2);

    if(isDatesEqual(date1,date2))
        printf("\nDates are same");
    else
        printf("\nDates are not same");

}

