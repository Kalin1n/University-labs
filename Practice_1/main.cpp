#include <iostream>
#include <algorithm>
#include <vector>
#include "Long.h"


using std::vector;

void Input(vector<Long> &data) {
    data.clear();

    std::cout << "Enter number of longs" << '\t';
    int n;
    std::cin >> n;

    data.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }
    std::cout << "=================\n\n";
}

void Output(const vector<Long> &input_data) {
    vector<Long> data = input_data;
    std::sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i];
    }
}

void Output_reversed(const vector<Long> &input_data) {
    vector<Long> data = input_data;
    std::sort(data.begin(), data.end());
    std::reverse(data.begin(), data.end());
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i];
    }
}

vector<Long, std::allocator<Long>>::const_iterator findMinIterator(const vector<Long> &data) {
    return std::min_element(data.begin(), data.end());
}

vector<Long, std::allocator<Long>>::const_iterator findMaxIterator(const vector<Long> &data) {
    return std::max_element(data.begin(), data.end());
}

long findMinIndex(const vector<Long> &data) {
    return (findMinIterator(data) - data.begin());
}

long findMaxIndex(const vector<Long> &data) {
    return (findMaxIterator(data) - data.begin());
}

Long findMinElement(const vector<Long> &data) {
    return *findMinIterator(data);
}

Long findMaxElement(const vector<Long> &data) {
    return *findMaxIterator(data);
}

void DeleteIf(vector<Long> &data) {
    double leftN, rightN;
    std::cout << "Enter range of values to delete:" << std::endl;
    std::cin >> leftN >> rightN;
    std::remove_if(data.begin(), data.end(), [&](Long element) {
        return ((element.getCentimeters() >= leftN) && (element.getCentimeters() <= rightN));
    });
}

void doubleElement(Long &_long) {
    _long = Long(0, _long.getCm() * 2);
}

vector<Long> DoubleElements(const vector<Long> &data) {
    vector<Long> result = data;
    std::for_each(result.begin(), result.end(), doubleElement);
    return result;
}

double DifferenceOfSum(const vector<Long> &before, const vector<Long> &after) {
    double beforeSum = 0;
    for (const auto &i : before) {
        beforeSum += i.getCm();
    }

    double afterSum = 0;
    for (const auto &i : after) {
        afterSum += i.getCm();
    }

    return (afterSum - beforeSum);
}

vector<Long> Merge(const vector<Long> &c1, const vector<Long> &c2) {
    vector<Long> result = c1;
    result.insert(result.end(), c2.begin(), c2.end());
    std::sort(result.begin(), result.end());
    auto last = std::unique(result.begin(), result.end());
    result.erase(last, result.end());
    return result;
}

int main() {
    vector<Long> data;
    Input(data);

    std::cout << "Min element index=" << findMinIndex(data) << std::endl;
    std::cout << "Max element index=" << findMaxIndex(data) << std::endl;

    Output(data);
    std::cout << std::endl;
    Output_reversed(data);
    std::cout << std::endl;

    data.push_back(findMaxElement(data) + findMinElement(data));

    DeleteIf(data);

    vector<Long> doubleData = DoubleElements(data);

    std::cout << "\nDifference=" << DifferenceOfSum(data, doubleData) << " cm\n" << std::endl;

    vector<Long> answer = Merge(data, doubleData);

    Output(answer);

    return 0;
}