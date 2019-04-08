#include <stdio.h>
#include <conio.h>
#include <windows.h>
// a calculator program & coded by Amirdementor

void gotoxy( int column, int line ) // gotoxy function
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  } // end of gotoxy function

int wherex() // wherex function
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.X;
} // end of wherex function

int wherey() // wherey function
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
} // end of wherey function

void squreSelect (int x , int y){ // squreselect function
gotoxy(x-1,y);
printf("|");
gotoxy(x+1,y);
printf("|");
gotoxy(x,y-1);
printf("-");
gotoxy(x,y+1);
printf("-");
gotoxy(x,y);
} // end of squreselect function

void squreDeselect (int x , int y) { // squredeselect function
gotoxy(x-1,y);
printf(" ");
gotoxy(x+1,y);
printf(" ");
gotoxy(x,y-1);
printf(" ");
gotoxy(x,y+1);
printf(" ");
gotoxy(x,y);
} // end of squredeselect function

int choose (int x_place , int y_place){ // choose function
    if (x_place==2 && y_place==2)
        return 1;
    if (x_place==7 && y_place==2)
        return 2;
    if (x_place==12 && y_place==2)
        return 3;
    if (x_place==2 && y_place==5)
        return 4;
    if (x_place==7 && y_place==5)
        return 5;
    if (x_place==12 && y_place==5)
        return 6;
    if (x_place==2 && y_place==8)
        return 7;
    if (x_place==7 && y_place==8)
        return 8;
    if (x_place==12 && y_place==8)     // this function return what you choose when you press enter key
        return 9;
    if (x_place==2 && y_place==11)
        return '.';
    if (x_place==7 && y_place==11)
        return 0;
    if (x_place==12 && y_place==11)
        return '=';
    if (x_place==17 && y_place==2)
        return '*';
    if (x_place==17 && y_place==5)
        return '/';
    if (x_place==17 && y_place==8)
        return '-';
    if (x_place==17 && y_place==11)
        return '+';
} // end of choose function

float old_num = 0; // define an integer
float a_num = 0; // define an integer  // I define these integers here because they don't change whenever the function was called
int b = 28; // define an integer
int operand = 0; // define an integer
int hasel (int new_num){ // a function for process of calculator and return hasel
if (new_num==1){
    old_num*=10; // zarb in 10 is for that program do not work only with one digit number
    old_num+=1;
}
if (new_num==2){
    old_num*=10;
    old_num+=2;
}
if (new_num==3){
    old_num*=10;
    old_num+=3;
}
if (new_num==4){
    old_num*=10;
    old_num+=4;
}
if (new_num==5){
    old_num*=10;
    old_num+=5;
}
if (new_num==6){
    old_num*=10;
    old_num+=6;
}
if (new_num==7){
    old_num*=10;
    old_num+=7;
}
if (new_num==8){
    old_num*=10;
    old_num+=8;
}
if (new_num==9){
    old_num*=10;
    old_num+=9;
}
if (new_num==0){
    old_num*=10;
}
if (new_num==46){ // float number
    if (operand==43 || operand==0){
        a_num+=old_num;
    }
    if (operand==45){
        a_num-=old_num;
    }
    if (operand==42){
        a_num*=old_num;
    }
    if (operand==47){
        a_num/=old_num;
    }
    operand=new_num;
    old_num=0;
}
if (new_num==43){ // jam
    if (operand==0 || operand==43){
        a_num+=old_num;
    }
    if (operand==45){
        a_num-=old_num;
    }
    if (operand==42){
        a_num*=old_num;
    }
    if (operand==47){
        a_num/=old_num;
    }
    if (operand == 46){
    if (old_num>=0 && old_num<10){
        old_num=old_num/10;
    }
    if (old_num>=10 && old_num<100){
        old_num=old_num/100;
    }
    if (old_num>=100 && old_num<100){
        old_num=old_num/1000;
    }
    a_num+=old_num;
}
    operand = new_num;
    old_num = 0;
} // end of jam
if (new_num == 45){ // tafrigh
    if (operand==0 || operand==43){
        a_num+=old_num;
    }
    if (operand==45){
        a_num-=old_num;
    }
    if (operand==42){
        a_num*=old_num;
    }
    if (operand==47){
        a_num/=old_num;
    }
    if (operand == 46){
    if (old_num>=0 || old_num<10){
        old_num=old_num/10;
    }
    if (old_num>=10 || old_num<100){
        old_num=old_num/100;
    }
    if (old_num>=100 || old_num<100){
        old_num=old_num/1000;
    }
    a_num+=old_num;
}
    operand = new_num;
    old_num = 0;
} // end of tafrigh
if (new_num == 42){ // zarb
    if (operand==0 || operand==43){
        a_num+=old_num;
    }
    if (operand==45){
        a_num-=old_num;
    }
    if (operand==42){
        a_num*=old_num;
    }
    if (operand==47){
        a_num/=old_num;
    }
    if (operand == 46){
    if (old_num>=0 || old_num<10){
        old_num=old_num/10;
    }
    if (old_num>=10 || old_num<100){
        old_num=old_num/100;
    }
    if (old_num>=100 || old_num<100){
        old_num=old_num/1000;
    }
    a_num+=old_num;
}
    operand = new_num;
    old_num = 0;
}
if (new_num == 47){ // taghsim
    if (operand==0 || operand==43){
        a_num+=old_num;
    }
    if (operand==45){
        a_num-=old_num;
    }
    if (operand==42){
        a_num*=old_num;
    }
    if (operand==47){
        a_num/=old_num;
    }
    if (operand == 46){
    if (old_num>=0 && old_num<10){
        old_num=old_num/10;
    }
    if (old_num>=10 && old_num<100){
        old_num=old_num/100;
    }
    if (old_num>=100 && old_num<100){
        old_num=old_num/1000;
    }
    a_num+=old_num;
}
    operand = new_num;
    old_num = 0;
}
if (new_num==61){ // for return the final answer
        switch (operand){
        case 43:
            gotoxy(b,5);
            printf("%.3f",a_num + old_num); // jam
            break;
        case 45:
            gotoxy(b,5);
            printf("%.3f",a_num - old_num); // tafrigh
            break;
        case 42:                     // in this way last result return whit switch and case way
            gotoxy(b,5);
            printf("%.3f",a_num * old_num); // zarb
            break;
        case 47:
            gotoxy(b,5);
            printf("%.3f",a_num / old_num); // taghsim
            break;
        case 46:
    if (old_num>=0 && old_num<10){
        old_num=old_num/10;
    }
    if (old_num>=10 && old_num<100){
        old_num=old_num/100;
    }
    if (old_num>=100 && old_num<100){ // float numbers
        old_num=old_num/1000;
    }
    a_num+=old_num;
            gotoxy(b,5);
            printf("%.3f",a_num);
            break;
        } // end of switch
} // end of if
//return last_hasel;
}// end of hasel function

void print_select (int i , int c){ // print_select function for show what user select
if (i==2 && c==11){
    printf("%c",choose(i,c));
}
if (i==12 && c==11){
    printf("%c",choose(i,c));
}
if (i==17 && c==2){               // after choose function decide to what select this function see if what you choose are an digit or if
    printf("%c",choose(i,c));     // your choose was a operator decide to how print it
}
if (i==17 && c==5){
    printf("%c",choose(i,c));
}
if (i==17 && c==8){
    printf("%c",choose(i,c));
}
if (i==17 && c==11){
    printf("%c",choose(i,c));
}
if (i!=17 && c!=11){
    printf("%d",choose(i,c));
}
if (i==7 && c==11) {
    printf("%d",choose(i,c));
}
} // end of print select function

int main(){
    int i,j,a=1;
    for (i=2; i<=8; i=i+3){ // loop for show 1 until 9 in exit page
        for (j=2; j<=12; j=j+5){
        gotoxy(j,i);
    printf("%d",a);
    a++;
    }
    } // end of for loop
    gotoxy(2,11); // for show operands on the exit page
    printf(".");
    gotoxy(7,11);
    printf("0");
    gotoxy(22,1);
    printf("WELL COME");
    gotoxy(12,11);
    printf("=");
    gotoxy(17,2);
    printf("*");
    gotoxy(17,5);
    printf("/");
    gotoxy(17,8);
    printf("-");
    gotoxy(17,11);
    printf("+"); // end of show operands
    gotoxy(7,5);
    squreSelect(7,5);
    while(1){ // for move square
        char press;
        press = getch();
        int i = wherex();
        int c = wherey();
        switch (press){
            case 75: // left
                if(i>2){
                squreDeselect(i,c);
                squreSelect(i-5,c);
                }
                break;
            case 77: // right
                if(i<17){
                squreDeselect(i,c);
                squreSelect(i+5,c);
                }
                break;
            case 72: // up
                if(c>2){
                squreDeselect(i,c);
                squreSelect(i,c-3);
                }
                break;
            case 80: // down
                if(c<11){
                squreDeselect(i,c);
                squreSelect(i,c+3);
                }
                break;
            case 13: // choose
                            squreDeselect(i,c);
                            gotoxy(b,5);
                                b++;
                            print_select(i,c);
                            hasel(choose(i,c));
                            gotoxy(7,5);
                            squreSelect(7,5);
                            break;
            case 49:
                squreDeselect(i,c);
                squreSelect(2,2);
                hasel(1);
                gotoxy(b,5);
                b++;
                printf("1");
                gotoxy(2,2);
                break;
            case 50:
                squreDeselect(i,c);
                squreSelect(7,2);
                hasel(2);
                gotoxy(b,5);
                b++;
                printf("2");
                gotoxy(7,2);
                break;
            case 51:
                squreDeselect(i,c);
                squreSelect(12,2);
                hasel(3);
                gotoxy(b,5);
                b++;
                printf("3");
                gotoxy(12,2);
                break;
            case 52:
                squreDeselect(i,c);
                squreSelect(2,5);
                hasel(4);
                gotoxy(b,5);
                b++;
                printf("4");
                gotoxy(2,5);
                break;
            case 53:
                squreDeselect(i,c);
                squreSelect(7,5);
                hasel(5);
                gotoxy(b,5);
                b++;
                printf("5");
                gotoxy(7,5);
                break;
            case 54:
                squreDeselect(i,c);
                squreSelect(12,5);
                hasel(6);
                gotoxy(b,5);
                b++;
                printf("6");
                gotoxy(12,5);
                break;
            case 55:
                squreDeselect(i,c);
                squreSelect(2,8);
                hasel(7);
                gotoxy(b,5);
                b++;
                printf("7");
                gotoxy(2,8);
                break;
            case 56:
                squreDeselect(i,c);
                squreSelect(7,8);
                hasel(8);
                gotoxy(b,5);
                b++;
                printf("8");
                gotoxy(7,8);
            break;
            case 57:
                squreDeselect(i,c);
                squreSelect(12,8);
                hasel(9);
                gotoxy(b,5);
                b++;
                printf("9");
                gotoxy(12,8);
                break;
            case 48:
                squreDeselect(i,c);
                squreSelect(7,11);
                hasel(0);
                gotoxy(b,5);
                b++;
                printf("0");
                gotoxy(7,11);
                break;
            case 61:
                squreDeselect(i,c);
                squreSelect(12,11);
                gotoxy(b,5);
                b++;
                printf("=");
                hasel(61);
                gotoxy(12,11);
                break;
            case 43:
                squreDeselect(i,c);
                squreSelect(17,11);
                hasel(43);
                gotoxy(b,5);
                b++;
                printf("+");
                gotoxy(17,11);
                break;
            case 45:
                squreDeselect(i,c);
                squreSelect(17,8);
                hasel(45);
                gotoxy(b,5);
                b++;
                printf("-");
                gotoxy(17,8);
                break;
            case 42:
                squreDeselect(i,c);
                squreSelect(17,2);
                hasel(42);
                gotoxy(b,5);
                b++;
                printf("*");
                gotoxy(17,2);
                break;
            case 47:
                squreDeselect(i,c);
                squreSelect(17,5);
                hasel(47);
                gotoxy(b,5);
                b++;
                printf("/");
                gotoxy(17,5);
                break;
            case 46:
                squreDeselect(i,c);
                squreSelect(2,11);
                hasel(46);
                gotoxy(b,5);
                b++;
                printf(".");
                gotoxy(2,11);
                break;
            case 27:
                gotoxy(5,22); // for take return of main down
                return 0;
        } // end of switch
    }
return 0;
} // end of main
