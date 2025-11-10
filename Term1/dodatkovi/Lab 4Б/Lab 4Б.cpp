// Lab 4Б.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   srand((unsigned)time(NULL));

   const int example = 10;
   int correctAnswer = 0;

   printf("Перевірка знань таблиці множення.\n");
   printf("Відповідайте числом > \n\n");

   for (int i = 1; i <= example; i++) {
       int a = rand() % 8 + 2;  
       int b = rand() % 8 + 2;  
       int userAnswer;

       printf("%d) %d * %d = ", i, a, b);

       if (scanf("%d", &userAnswer) != 1) {
           printf("Некоректне введення.\n");
           return 1;
       }

       if (userAnswer == a * b) {
           correctAnswer++;
           printf("Правильно.\n\n");
       }
       else {
           printf("Неправильно. Правильна відповідь > %d\n\n", a * b);
       }
   }

   printf("Кількість правильних відповідей > %d з %d.\n", correctAnswer, example);

   int grade;

   switch (correctAnswer) {
   case 10:
       grade = 5;
       break;
   case 9:
       grade = 4;
       break;
   case 8:
   case 7:
       grade = 3;
       break;
   default:
       grade = 2;
       break;
   }

   printf("Оцінка > %d\n", grade);

   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
