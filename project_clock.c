#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

#define ROW 9
#define COL 11
#define CHARACTER '*'

void zero(int x, int y);
void one(int x, int y);
void two(int x, int y);
void three(int x, int y);
void four(int x, int y);
void five(int x, int y);
void six(int x, int y);
void seven(int x, int y);
void eight(int x, int y);
void nine(int x, int y);
void colon(int x, int y);
void gotoxy(int, int); // Only works on command prompt (will not work on vs code's terminal)
void print_digit(int, int, int); // to call the functions that will print the digits.
// void ringtone(); // will assign the ringtone
static inline int gap_hor(int *);
static inline int gap_ver(int *);

void gm_time(); // return type: none, parameter type: none
void local_time(); // return type: none, parameter type: none
void clock_local(); // return type: none, parameter type: none (shows the clock and time changes each second)
void alarm(uint8_t, uint8_t, uint8_t); // return type: none, parameter type: int (after how many HH:MM:SS to ring). will play the song after the specified amount of time.
void timer(uint8_t, uint8_t, uint8_t); // return type: none, parameter type: int (after how many HH:MM:SS to stop). counting backwards

/* CURRENTLY UNDER PROCESS
1. void stopwatch(); // return type: none, parameter type: none (will just show the amount of time passed in form of HH:MM:SS)
*/

int main(void){
    system("color 3f");
    
    while(1){
        int choice;
        int hour, minute, second;
        printf("Enter 1 for Greenwich Time\n");
        printf("Enter 2 for Local Time\n");
        printf("Enter 3 for clock (Based on local standard time)\n");
        printf("Enter 4 for setting up alarm (Format: HH:MM:SS)\n");
        printf("Enter 5 for setting up timer (Format: HH:MM:SS)\n");
        printf("Enter any other numerical key to exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: // ascii code for 1
                gm_time();
                break;
            case 2: // ascii code for 2
                local_time();
                break;
            case 3: // ascii code for 3
                clock_local();
                break;
            case 4: // ascii code for 4
                printf("Enter hour: ");
                scanf("%d", &hour);
                printf("Enter minute: ");
                scanf("%d", &minute);
                printf("Enter second: ");
                scanf("%d", &second);
                alarm(hour, minute, second); // calling the alarm function
                break;
            case 5: // ascii code for 5
                printf("Enter hour: ");
                scanf("%d", &hour);
                printf("Enter minute: ");
                scanf("%d", &minute);
                printf("Enter second: ");
                scanf("%d", &second);
                timer(hour, minute, second); // calling the timer function
                break;
            default:
                exit(0);
        }

        system("CLS");
    }
    
    return 0;
}

void timer(uint8_t hour, uint8_t minute, uint8_t second){
    // timer can be set max to 99:59:59

    if(hour > 99 || minute > 59 || second > 59){
        printf("Wrong detail (Choose time correctly)\n");
        return;
    }

    // starting co-ordinates
    int x = 20;
    int y = 15;

    while(hour != 0 || minute != 0 || second != 0){
        system("CLS"); // clear screen

        // HOUR
        print_digit(hour/10, x, y);
        print_digit(hour%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // MINUTE
        print_digit(minute/10, gap_hor(&x), y);
        print_digit(minute%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // SECOND
        print_digit(second/10, gap_hor(&x), y);
        print_digit(second%10, gap_hor(&x), y);

        if(second == 0 && (minute != 0 || hour != 0)){
            minute--;
            second = 60; // second is already decreasing so if we assign it 59 then we'll decrease it by 2 sec once every minute.
        }
        if(minute == 0 && hour != 0){
            hour--;
            minute = 59;
        }
        second--;
        sleep(1); // sleep for 1 second

        x = 20;
        y = 15;
    }

    // 00 will shown when the timers end
    // HOUR
    print_digit(0, x, y);
    print_digit(0, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // MINUTE
    print_digit(0, gap_hor(&x), y);
    print_digit(0, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // SECOND
    print_digit(0, gap_hor(&x), y);
    print_digit(0, gap_hor(&x), y);

    getch();
    system("CLS");
}

void alarm(uint8_t hr, uint8_t min, uint8_t sec){
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    // If wrong digits are given (we can set alarm to 24:00:00)
    if(hr == 24 && (min > 0 || sec > 0)){
        printf("Wrong Details (Choose time correctly)\n");
        return;
    }
    if(hr > 24 || min > 59 || sec > 59){
        printf("Wrong Details (Choose time correctly)\n");
        return;
    }

    // If alarm is set for next day (alarm can be set in future till 24:00:00 (today))
    if((hr < local_time->tm_hour) || 
    (hr == local_time->tm_hour && min < local_time->tm_min) ||
    (hr == local_time->tm_hour && min == local_time->tm_min && sec <= local_time->tm_sec)){
        printf("OOPS! Set the alarm with today's time\n");
        return;
    }

    system("CLS"); // first of all clearing the console

    while(1){
        now = time(NULL);
        local_time = localtime(&now);

        uint8_t hour = local_time->tm_hour; // stores hour
        uint8_t minute = local_time->tm_min; // stores minute
        uint8_t second = local_time->tm_sec; // stores second

        // starting co-ordinates
        int x = 20;
        int y = 15;

        // HOUR
        print_digit(hour/10, x, y);
        print_digit(hour%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // MINUTE
        print_digit(minute/10, gap_hor(&x), y);
        print_digit(minute%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // SECOND
        print_digit(second/10, gap_hor(&x), y);
        print_digit(second%10, gap_hor(&x), y);

        printf("\n\nAlarm will stop at: %2d:%2d:%2d\n", hr, min, sec);

        if(local_time->tm_hour == hr && local_time->tm_min == min && local_time->tm_sec == sec) break; // stopping the display of time after 1 minute currently.
        sleep(1); // sleep for 1 second
        system("CLS"); // clear screen
    }

    getch();
    system("CLS");
}

void clock_local(){
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    int stop_time = now+10; /*
    Because we have used sleep(1) the clock will stop approximately after 59 sec.
    -> Why not exactly after 60 sec?
    -> Becase some operations are happeing which will take some time in each iteration which will be negligible (but somthing will be there).
    */

    system("CLS"); // first of all clearing the console

    while(1){
        now = time(NULL);
        local_time = localtime(&now);

        uint8_t hour = local_time->tm_hour; // stores hour
        uint8_t minute = local_time->tm_min; // stores minute
        uint8_t second = local_time->tm_sec; // stores second

        // starting co-ordinates
        int x = 20;
        int y = 15;

        // HOUR
        print_digit(hour/10, x, y);
        print_digit(hour%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // MINUTE
        print_digit(minute/10, gap_hor(&x), y);
        print_digit(minute%10, gap_hor(&x), y);
        colon(gap_hor(&x), y);

        // SECOND
        print_digit(second/10, gap_hor(&x), y);
        print_digit(second%10, gap_hor(&x), y);

        if(now == stop_time) break; // stopping the display of time after 1 minute currently.
        sleep(1); // sleep for 1 second
        system("CLS"); // clear screen
    }

    getch();
    system("CLS");
}

void local_time(){
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    uint8_t hour = local_time->tm_hour; // stores hour
    uint8_t minute = local_time->tm_min; // stores minute
    uint8_t second = local_time->tm_sec; // stores second

    // starting co-ordinates
    int x = 20;
    int y = 15;

    system("CLS"); // first of all clearing the console

    // HOUR
    print_digit(hour/10, x, y);
    print_digit(hour%10, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // MINUTE
    print_digit(minute/10, gap_hor(&x), y);
    print_digit(minute%10, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // SECOND
    print_digit(second/10, gap_hor(&x), y);
    print_digit(second%10, gap_hor(&x), y);

    getch(); // takes a char input and does nothing
    system("CLS"); // clear screen
}

void gm_time(){
    time_t now = time(NULL);
    struct tm *gm_time = gmtime(&now);

    uint8_t hour = gm_time->tm_hour; // stores hour
    uint8_t minute = gm_time->tm_min; // stores minute
    uint8_t second = gm_time->tm_sec; // stores second

    // starting co-ordinates
    int x = 20;
    int y = 15;

    system("CLS"); // first of all clearing the console

    // HOUR
    print_digit(hour/10, x, y);
    print_digit(hour%10, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // MINUTE
    print_digit(minute/10, gap_hor(&x), y);
    print_digit(minute%10, gap_hor(&x), y);
    colon(gap_hor(&x), y);

    // SECOND
    print_digit(second/10, gap_hor(&x), y);
    print_digit(second%10, gap_hor(&x), y);

    getch(); // takes a char input and does nothing
    system("CLS"); // clear screen
}

void zero(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || j == 0 || i == ROW-1 || j == COL-1)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void one(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(j == COL/2)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void two(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || i == ROW-1 || (j == COL-1 && i < ROW/2) || i == ROW/2 || (j == 0 && i > ROW/2))
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void three(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || i == ROW-1 || j == COL-1 || i == ROW/2)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void four(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(j == COL-1 || (j == 0 && i < ROW/2) || i == ROW/2)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void five(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || (j == 0 && i < ROW/2) || i == ROW/2 || (j == COL-1 && i > ROW/2) || i == ROW-1)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void six(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || j == 0 || i == ROW-1 || (j == COL-1 && i > ROW/2) || i == ROW/2)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void seven(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || j == COL-1)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void eight(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || j == 0 || i == ROW-1 || j == COL-1 || i == ROW/2)
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void nine(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if(i == 0 || i == ROW-1 || j == COL-1 || i == ROW/2 || (j == 0 && i < ROW/2))
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void colon(int x, int y){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            gotoxy(x, y);
            if((i == ROW/4 && j == COL/2) || (i == ROW/2 + ROW/4 && j == COL/2))
                printf("%c", CHARACTER);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= COL;
        printf("\n");
    }
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_digit(int digit, int x, int y){
    switch(digit){
        case 1:
            one(x, y);
            break;
        case 2:
            two(x, y);
            break;
        case 3:
            three(x, y);
            break;
        case 4:
            four(x, y);
            break;
        case 5:
            five(x, y);
            break;
        case 6:
            six(x, y);
            break;
        case 7:
            seven(x, y);
            break;
        case 8:
            eight(x, y);
            break;
        case 9:
            nine(x, y);
            break;
        default:
            zero(x, y);
            break;
    }
}

static inline int gap_hor(int *x){
    return *x += COL + 3;
}

static inline int gap_ver(int *y){
    return *y += ROW + 3;
}