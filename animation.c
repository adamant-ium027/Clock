#include <stdio.h>
#include <windows.h>
#include <stdint.h>
#include <conio.h>

// DIGITS
void zero(char, uint8_t, uint8_t, uint8_t);
void one(char, uint8_t, uint8_t, uint8_t);
void two(char, uint8_t, uint8_t, uint8_t);
void three(char, uint8_t, uint8_t, uint8_t);
void four(char, uint8_t, uint8_t, uint8_t);
void five(char, uint8_t, uint8_t, uint8_t);
void six(char, uint8_t, uint8_t, uint8_t);
void seven(char, uint8_t, uint8_t, uint8_t);
void eight(char, uint8_t, uint8_t, uint8_t);
void nine(char, uint8_t, uint8_t, uint8_t);

// ALPHABETS
void a_alpha(char, uint8_t, uint8_t, uint8_t);
// void b_alpha(char, uint8_t, uint8_t, uint8_t);
void c_alpha(char, uint8_t, uint8_t, uint8_t);
// void d_alpha(char, uint8_t, uint8_t, uint8_t);
void e_alpha(char, uint8_t, uint8_t, uint8_t);
void f_alpha(char, uint8_t, uint8_t, uint8_t);
void g_alpha(char, uint8_t, uint8_t, uint8_t);
void h_alpha(char, uint8_t, uint8_t, uint8_t);
void i_alpha(char, uint8_t, uint8_t, uint8_t);
void j_alpha(char, uint8_t, uint8_t, uint8_t);
// void k_alpha(char, uint8_t, uint8_t, uint8_t);
void l_alpha(char, uint8_t, uint8_t, uint8_t);
void m_alpha(char, uint8_t, uint8_t, uint8_t);
void n_alpha(char, uint8_t, uint8_t, uint8_t);
// void o_alpha(char, uint8_t, uint8_t, uint8_t);
void p_alpha(char, uint8_t, uint8_t, uint8_t);
// void q_alpha(char, uint8_t, uint8_t, uint8_t);
void r_alpha(char, uint8_t, uint8_t, uint8_t);
// void s_alpha(char, uint8_t, uint8_t, uint8_t);
void t_alpha(char, uint8_t, uint8_t, uint8_t);
void u_alpha(char, uint8_t, uint8_t, uint8_t);
// void v_alpha(char, uint8_t, uint8_t, uint8_t);
void w_alpha(char, uint8_t, uint8_t, uint8_t);
void x_alpha(char, uint8_t, uint8_t, uint8_t);
void y_alpha(char, uint8_t, uint8_t, uint8_t);
void z_alpha(char, uint8_t, uint8_t, uint8_t);

// UTILITY FUNCTIONS
void gotoxy(uint8_t, uint8_t); // move the cursor to x, y co-ordinates
static inline void clear(); // calls system("CLS")

int main(void){
    int size = 11;
    int x = 20, y = 15;
    char ch = '*';

    clear();
    zero(ch, size, x, y); getch(); clear();
    one(ch, size, x, y); getch(); clear();
    two(ch, size, x, y); getch(); clear();
    three(ch, size, x, y); getch(); clear();
    four(ch, size, x, y); getch(); clear();
    five(ch, size, x, y); getch(); clear();
    six(ch, size, x, y); getch(); clear();
    seven(ch, size, x, y); getch(); clear();
    eight(ch, size, x, y); getch(); clear();
    nine(ch, size, x, y); getch(); clear();
    a_alpha(ch, size, x, y); getch(); clear();
    // b_alpha(ch, size, x, y); getch(); clear();
    c_alpha(ch, size, x, y); getch(); clear();
    // d_alpha(ch, size, x, y); getch(); clear();
    e_alpha(ch, size, x, y); getch(); clear();
    f_alpha(ch, size, x, y); getch(); clear();
    g_alpha(ch, size, x, y); getch(); clear();
    h_alpha(ch, size, x, y); getch(); clear();
    i_alpha(ch, size, x, y); getch(); clear();
    j_alpha(ch, size, x, y); getch(); clear();
    // k_alpha(ch, size, x, y); getch(); clear();
    l_alpha(ch, size, x, y); getch(); clear();
    m_alpha(ch, size, x, y); getch(); clear();
    n_alpha(ch, size, x, y); getch(); clear();
    // o_alpha(ch, size, x, y); getch(); clear();
    p_alpha(ch, size, x, y); getch(); clear();
    // q_alpha(ch, size, x, y); getch(); clear();
    r_alpha(ch, size, x, y); getch(); clear();
    // s_alpha(ch, size, x, y); getch(); clear();
    t_alpha(ch, size, x, y); getch(); clear();
    u_alpha(ch, size, x, y); getch(); clear();
    // v_alpha(ch, size, x, y); getch(); clear();
    w_alpha(ch, size, x, y); getch(); clear();
    x_alpha(ch, size, x, y); getch(); clear();
    y_alpha(ch, size, x, y); getch(); clear();
    z_alpha(ch, size, x, y); getch(); clear();

    return 0;
}

void a_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void r_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || j == 0 || (j == size-1 && i < size/2) || (i == j && j > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void g_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || j == 0 || (i == size-1 && j < size/2) || (i >= size/2 && j == size/2) || (i == size/2 && j > size/2) || (j == size-1 && i > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void m_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(j == 0 || j == size-1 || (i == j && j <= size/2) || (i == size-j-1 && j > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void w_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(j == 0 || j == size-1 || (i == j && j >= size/2) || (i == size-j-1 && j < size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void x_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == j || i == size-j-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void y_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == size-j-1 || (i == j && j < size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void z_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size-1 || (i == size-j-1))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void c_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || j == 0 || i == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void e_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || j == 0)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void f_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || j == 0)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void h_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == size/2 || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void i_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size-1 || j == size/2)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void j_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || j == size/2 || (i == size-1 && j < size/2) || (j == 0 && i > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void l_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == size-1 || j == 0)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void n_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == j || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void p_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || j == 0 || (j == size-1 && i < size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void t_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || j == size/2)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void u_alpha(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == size-1 || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void nine(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size-1 || i == size/2 || (j == 0 && i < size/2) || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void eight(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void seven(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void six(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || j == 0 || (j == size-1 && i > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void five(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || (j == 0 && i < size/2) || (j == size-1 && i > size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void four(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == size/2 || j == size-1 || (j == 0 && i < size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void three(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void two(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size/2 || i == size-1 || (j == 0 && i > size/2) || (j == size-1 && i < size/2))
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void one(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(j == size/2)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void zero(char ch, uint8_t size, uint8_t x, uint8_t y){
    for(uint8_t i=0; i<size; i++){
        for(uint8_t j=0; j<size; j++){
            gotoxy(x, y);
            if(i == 0 || i == size-1 || j == 0 || j == size-1)
                printf("%c", ch);
            else
                printf(" ");
            x++;
        }
        y++;
        x -= size;
        printf("\n");
    }
}

void gotoxy(uint8_t x, uint8_t y){
    if(x < 0) x = 0;
    if(y < 0) y = 0;

    COORD co_ord;
    co_ord.X = x;
    co_ord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co_ord);
}

static inline void clear(){
    system("CLS");
}