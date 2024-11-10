#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> summers; // vector с суммами

// сумма первых countOfFirst элементов
int sumFirstNumbers(vector<int> numbers, int countOfFirst)
{
    int summ = 0;
    // for (size_t i = 0; i < countOfFirst; i++)
    // {
    //     summ += numbers[i];
    // }
    if (countOfFirst == 0)
    {
        return numbers[0];
    }
    summ = numbers[countOfFirst] + summers[countOfFirst - 1];
    return summ;
}

int main()
{
    int n;

    cin >> n;
    vector<int> numbers(n, 0); // vector с числами
    summers.resize(n + 10);
    if (n == 1) // если число всего одно, то и вариантиков немного
    {
        cout << numbers[0];
        return 0;
    }

    for (size_t i = 0; i < n; ++i)
    {
        cin >> numbers[i]; // ввод зачнений
    }

    // сортировка, потому что наименьшие числа будут получаться только при сортировке по возрастанию.
    sort(numbers.begin(), numbers.end());

    int summ = 0;
    summers[0] = numbers[0];
    // summers[1] = numbers[1] + summers[0];

    for (size_t i = 0; i < n; i++)
    {
        summers[i] = sumFirstNumbers(numbers, i); // вычисление промежуточных сумм
        summ += summers[i];                       // подсчет общей суммы
    }

    cout << summ - numbers[0];
}