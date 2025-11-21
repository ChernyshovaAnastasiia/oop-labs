// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cmath>
using namespace std;
#define N 3
#define M 3

void Fun(int mas1[]);

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int mas1[N * M] = { 1,2,3,5,6,7,8,9,0 };

    cout << "Одновимірний масив ->\n";
    for (int i = 0; i < N * M; i++)
        cout << setw(4) << mas1[i];
    cout << endl;
     
	Fun(mas1);

    cout << "\nОдновимiрний масив (пiсля функцiї) ->\n";
    for (int i = 0; i < N * M; i++)
        cout << setw(4) << mas1[i];
}

void Fun(int mas1[])
{
    int mas2[N][M];
    double avg[M];

    cout << "\nДрук ДМ з ОМ ->\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mas2[i][j] = mas1[i * M + j];
            cout << setw(4) << mas2[i][j];
        }
        cout << endl;
    }


    for (int j = 0; j < M; j++) {
        double sum = 0;
        for (int i = 0; i < N; i++)
            sum += mas2[i][j];
        avg[j] = sum / N;
    }

    for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
            mas2[i][j] = round(mas2[i][j] * avg[j]);

    cout << "\nСередні значення стовпців ->\n";
    for (int j = 0; j < M; j++)
        cout << avg[j] << " ";

    cout << "\n\nДрук нового ДМ (пiсля множення на середнє стовпця) -> \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << setw(6) << mas2[i][j];
        cout << endl;
    }


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            mas1[i * M + j] = mas2[i][j];

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
