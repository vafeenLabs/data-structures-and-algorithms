#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX = 71;

int m[MAX][MAX];

int getNextNumberFromCIN(ifstream &filer)
{
    int nextNumber;

    filer >> nextNumber;

    return nextNumber;
}

int main()
{
    ifstream filer("cin.txt");

    // Обнуляем массив m
    memset(m, 0, sizeof(m));

    // Инициализация: f(i, 1) = f(0, i) = 1
    for (int i = 0; i < MAX; ++i)
    {
        m[1][i] = m[i][0] = 1;
    }

    // Предвычисления значений m[i][j]
    for (int i = 2; i < MAX; ++i)
    {
        for (int j = 1; j < MAX; ++j)
        {
            m[i][j] = m[i][j - 1] + m[i - 1][j];
        }
    }

    int tests = getNextNumberFromCIN(filer);

    while (tests--)
    {
        int n, t, p;
        n = getNextNumberFromCIN(filer);
        t = getNextNumberFromCIN(filer);
        p = getNextNumberFromCIN(filer);

        // Пересчитываем t
        t = t - n * p; // типо если у нас 10 минимум, 3 экзамнена, то мы из суммы
                    //    вычитаем суммарный максимум за 3 экзамена, у нас при сумме 34 остается 4
                    //    и нам нужно 4 разделить на 3 любыми способами:
                    //    0 0 4
                    //    0 4 0
                    //    4 0 0
                    //    0 3 1
                    //    и так далее - нужное нам разбиение 
                    //    и рекурсивно получается так, что 






        // Выводим результат
        cout << m[n][t] << endl;
    }

    return 0;
}
