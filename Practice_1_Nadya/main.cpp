/**
У довільному массивi обчислити:
– кількість елементів масиву, рівних нулю;
– суму елементів масиву, які лежать в діапазоні від А до В.
Впорядкувати елементи масиву за спаданням модулів елементів
 **/

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

#include "Task.h"

int main() {
    int n;
    std::cout << "Enter size of array\n";
    std::cin >> n;

    Task myTask(n);

    myTask.solve();

    return 0;
}