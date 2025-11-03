// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
    short n;
    double x, y;
    short h;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (n = 0; n < 5; n++) {
        printf("|   x   |      у     |\n");
        printf("|-------|------------|\n");

        for (x = 0; x < 8; x += 0.25) {
            if (x < 2) y = 2 - x;
            else 
                if (x < 4) y = 2 - sqrt(4 - (x - 2) * (x - 2));
            else 
                if (x<6) y = 6-x;
            else y = 2 - sqrt(4 - (x - 6) * (x - 6));

            printf("| %5.2lf | %11.7lf |", x + n * 8.0, y);

            h = (short)((y + 1) * 10);
            if (y - 1 - h * 10 > 0.5) h++;
            for (; h > 0; h--) printf(" "); 
            printf("*\n");
        }
            printf("Натисніть клавішу Enter...");
            getchar();
        }
    return 0;
}