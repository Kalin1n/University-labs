
#ifndef PRACTICE_1_NADYA_TASK_H
#define PRACTICE_1_NADYA_TASK_H

class Task {
private:
    vector<int> array;
    int size;
    int sum = 0;
    long count = 0;
    int left, right;


    void input() {
        std::cout << "Enter elements\n";
        for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
        }
    }

    void find_number_of_zeros() {
        count = std::count_if(array.begin(), array.end(), [](int element) { return element == 0; });
    }

    void find_sum_in_interval() {
        std::cout << "Enter the borders\n";
        std::cin >> left >> right;
        std::for_each(array.begin(), array.end(), [&](int element) {
            if (left <= element && element <= right) {
                sum += element;
            }
        });
    }

    void sort_array() {
        std::sort(array.begin(), array.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
    }

    void output() {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
    }

public:
    Task(int n = 0) {
        size = n;
        array.resize(size);
    }

    void solve() {
        input();
        find_number_of_zeros();
        find_sum_in_interval();
        sort_array();
        std::cout << "Number of zero elements=" << count << "\n";
        std::cout << "Sum in interval=" << sum << "\n";
        output();
    }


};

#endif //PRACTICE_1_NADYA_TASK_H
