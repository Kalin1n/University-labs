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

long max_index(const vector<int> &data) {
    return (std::max_element(data.begin(), data.end(),
                             [](int lhs, int rhs) {
                                 return abs(lhs) < abs(rhs);
                             }) - data.begin());
}

int find_sum(const vector<int> &data) {

    auto firstPositiveIndex = std::find_if(data.begin(), data.end(), [](int element) {
        return element > 0;
    }) - data.begin();

    int sum = 0;

    for (long i = firstPositiveIndex + 1; i < data.size(); ++i) {
        sum += abs(data[i]);
    }


    return sum;
}

int main() {
    int n;

    std::cout << "Enter size of array" << std::endl;
    std::cin >> n;

    vector<int> array(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    std::cout << "Max abs element index=" << max_index(array) << "\n";
    std::cout << "Sum of abs after first positive=" << find_sum(array) << "\n";

    int left, right;

    std::cout << "Enter borders:\n";
    std::cin >> left >> right;

    std::sort(array.begin(), array.end(), [&](int a, int b) -> bool {
        return ((left <= a && a <= right) && !(left <= b && b <= right));
    });

    for (int i : array) {
        std::cout << i << "\t";
    }

    return 0;
}