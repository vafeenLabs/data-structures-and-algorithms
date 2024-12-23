#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


vector<vector<int>> X = {{2, 1}, {5, 1}, {3, 3}, {6, 4}};
int N = X.size();
double MAX = 0; // N-колво точек на плоскости; Х[N]-точки; MAX-максимальный периметр

// Проверяет, есть ли в массиве A
// одинаковые точки (вершины).
// Если есть, возвращает true, иначе false.
bool twins(vector<vector<int>> A)
{ // чтобы убрать перестановки с одинаковыми элементами
    int U = 0;
    for (int i = 0; i < N + 1; i++)
    {
        for (int k = 1; (k + i < N + 1); k++)
        {
            if ((A[i][0] == A[i + k][0]) and (A[i][1] == A[i + k][1]))
                U += 1;
        }
    }
    if (U > 1)
        return true; // потому что первый и последний элемент я сделал одинаковыми
    else
        return false;
}

// проверка пересечения линий (сложна, не смотрите)
bool peresekayoutsya_li_linii(
    vector<int> a,
    vector<int> b,
    vector<int> c,
    vector<int> d)
{
    float dx1 = b[0] - a[0];
    float dy1 = b[1] - a[1];
    float dx2 = d[0] - c[0];
    float dy2 = d[1] - c[1];

    float a1 = -dy1;
    float b1 = +dx1;
    float d1 = -(a1 * a[0] + b1 * a[1]);

    float a2 = -dy2;
    float b2 = +dx2;
    float d2 = -(a2 * c[0] + b2 * c[1]);

    float seg1_st = a2 * a[0] + b2 * a[1] + d2;
    float seg1_end = a2 * b[0] + b2 * b[1] + d2;
    float seg2_st = a1 * c[0] + b1 * c[1] + d1;
    float seg2_end = a1 * d[0] + b1 * d[1] + d1;

    if ((((c[0] - a[0]) * dy1 - (c[1] - a[1]) * dx1) == 0) && (c[0] <= max(a[0], b[0])) && (c[0] >= min(a[0], b[0])) && (c[1] <= max(a[1], b[1])) && (c[1] >= min(a[1], b[1])))
        return true;
    if ((((d[0] - a[0]) * dy1 - (d[1] - a[1]) * dx1) == 0) && (d[0] <= max(a[0], b[0])) && (d[0] >= min(a[0], b[0])) && (d[1] <= max(a[1], b[1])) && (d[1] >= min(a[1], b[1])))
        return true;
    if ((((a[0] - c[0]) * dy2 - (a[1] - c[1]) * dx2) == 0) && (a[0] <= max(c[0], d[0])) && (a[0] >= min(c[0], d[0])) && (a[1] <= max(c[1], d[1])) && (a[1] >= min(c[1], d[1])))
        return true;
    if ((((b[0] - c[0]) * dy2 - (b[1] - c[1]) * dx2) == 0) && (b[0] <= max(c[0], d[0])) && (b[0] >= min(c[0], d[0])) && (b[1] <= max(c[1], d[1])) && (b[1] >= min(c[1], d[1])))
        return true;

    if (seg1_st * seg1_end >= 0 || seg2_st * seg2_end >= 0)
        return false;

    return true;
}

// поиск периметра многоугольника
double Perimetr(vector<vector<int>> A)
{
    double P = 0;
    for (int i = 0; i < N; i++)
        P += sqrt(pow((A[i + 1][0] - A[i][0]), 2) + pow((A[i + 1][1] - A[i][1]), 2));
    return P;
}

void Backtracking(int k)
{
    static vector<vector<int>> A(N + 1, vector<int>(2, 0));
    // static int A[N + 1][2];
    if (k == 0)
    {
        A[0][0] = X[0][0];
        A[0][1] = X[0][1];
        Backtracking(k + 1);
    }
    else if (k == N)
    {
        A[N][0] = X[0][0];
        A[N][1] = X[0][1];
        int a = 0;
        for (int i = 0, j = 1; (i < N + 1 && j < N + 1); i += 1, j += 1)
        {
            for (int k = 2; (k + i < N + 1 && k + j < N + 1); k += 1)
            {
                if ((peresekayoutsya_li_linii(A[i], A[j], A[i + k], A[j + k])) == 1)
                    a += 1;
            }
            if (i == 0)
                a -= 1;
        }

        if (twins(A) == 1)
            a += 1;

        if (a == 0)
        {
            if (MAX < Perimetr(A))
            {
                MAX = Perimetr(A);
                // cout << MAX << '\n';
                for (int i = 0; i < N + 1; i++)
                    cout << "(" << A[i][0] << ";" << A[i][1] << ")";
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 1; i < N; i++)
        {
            A[k][0] = X[i][0];
            A[k][1] = X[i][1];
            Backtracking(k + 1);
        }
    }
}

int main()
{
    Backtracking(0);
    cout << "\n\n"
         << MAX;

    cout << "\n\n\n";
}
