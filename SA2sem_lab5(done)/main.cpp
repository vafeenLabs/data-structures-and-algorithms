#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// обход к глубину 
void dfs(int v, vector<int>& colors, vector<vector<int>>& graph, vector<stack<int>>& vector_of_stacks, vector<int>& result) {
    int color = colors[v]; //Получаем цвет текущей вершины.
    if (vector_of_stacks[color].empty())
        result[v] = -1; //Если стек для данного цвета пуст, устанавливаем результат для вершины в -1.
    else
        result[v] = vector_of_stacks[color].top(); // берем результат из вершины на вершине стека.

    vector_of_stacks[color].push(v); //Добавляем текущую вершину в стек для соответствующего цвета.

    for (int i = 0; i < graph[v].size(); ++i) { //Обходим всех соседей текущей вершины.
        int to = graph[v][i];
        dfs(to, colors, graph, vector_of_stacks, result);//Рекурсивно вызываем dfs для следующей вершины.
    }
    vector_of_stacks[color].pop(); //Удаляем текущую вершину из стека.
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<vector<int>> graph(n + 1);
    for (int i = 2; i <= n; ++i) {
        int val;
        cin >> val;
        graph[val].push_back(i);
    }

    vector<int> colors(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> colors[i];

    vector<stack<int>> vector_of_stacks(c + 1);
    vector<int> result(n + 1);
    dfs(1, colors, graph, vector_of_stacks, result);

    for (int i = 1; i <= n; ++i)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
