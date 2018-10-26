/**
 * Variant 5
 В одновимірному масиві елементів, обчислити:
– номер максимального за модулем елемента;
– суму модулів елементів, які розташовані після першого додатного
елемента.
Перетворити масив таким чином, щоб спочатку розташовувались всі
елементи, ціла частина яких лежить в інтервалі [a,b], а потім – всі інші
 * **/

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

#include "Task.h"


int main() {
    int n;

    std::cout << "Enter size of array" << std::endl;
    std::cin >> n;

    Task myTask(n);
    myTask.do_task();

    return 0;
}