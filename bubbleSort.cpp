#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& rand_array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; j++) {
            if (rand_array[j] > rand_array[j+1]) {
                std::swap(rand_array[j], rand_array[j + 1]);
            }
        }
    }
}

template <typename T>
void print_array(const std::vector<T>& rand_array) {
    for (const T& element : rand_array) {
        std::cout << element << ";";
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Enter number of elements: ";
    std::cin >> size;

    std::vector<double> rand_array(size);
    srand(time(0));

    for (int i = 0; i < size; i++) {
        rand_array[i] = rand() % 100000 + 1;;
    }

    std::cout << "Before the sorting: ";
    print_array(rand_array);

    bubbleSort(rand_array, size);

    std::cout << "After: ";
    print_array(rand_array);

    return 0;
}