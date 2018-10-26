//
// Created by balik on 26.10.18.
//

#ifndef LAB_1_TASK_H
#define LAB_1_TASK_H

class Task {
private:
    vector<int> data;
    int size;
    int left, right;
    int max_index;
    int sum;

    void input() {
        std::cout << "Enter elements:\n";
        for (int i = 0; i < size; ++i) {
            std::cin >> data[i];
        }
    }

    void find_sum() {
        auto firstPositiveIndex = std::find_if(data.begin(), data.end(), [](int element) {
            return element > 0;
        }) - data.begin();

        sum = 0;

        for (long i = firstPositiveIndex + 1; i < data.size(); ++i) {
            sum += abs(data[i]);
        }
    }


    void find_max_index() {
        max_index = (std::max_element(data.begin(), data.end(),
                                      [](int lhs, int rhs) {
                                          return abs(lhs) < abs(rhs);
                                      }) - data.begin());
    }

    void sort_array() {
        std::cout << "Enter borders:\n";
        std::cin >> left >> right;

        std::sort(data.begin(), data.end(), [&](int a, int b) -> bool {
            return ((left <= a && a <= right) && !(left <= b && b <= right));
        });
    }

    void output() {
        for (int i : data) {
            std::cout << i << "\t";
        }
    }

public:

    Task(int n = 0) {
        size = n;
        data.resize(size);
    }


    void do_task() {
        input();
        find_sum();
        find_max_index();
        sort_array();
        std::cout << "Max abs element index=" << max_index << "\n";
        std::cout << "Sum of abs after first positive=" << sum << "\n";
        output();
    }

};

#endif //LAB_1_TASK_H
