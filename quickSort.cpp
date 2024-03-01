#include <iostream>
#include <vector>
#include <random>


template <typename T>
int partition(std::vector<T>& rand_array, int first, int last) {
    T pivot = rand_array[last];
    int i = first - 1;

    for (int j = first; j <= last - 1; j++) {
        if (rand_array[j] < pivot) {
            i++;
            std::swap(rand_array[i], rand_array[j]);
        }
    }

    std::swap(rand_array[i + 1], rand_array[last]);
    return i + 1;
}

template <typename T>
int makeRandomPivotLast(std::vector<T>& rand_array, int first, int last) {
    srand(time(0));
    int random_index = first + rand() % (last - first);
    std::swap(rand_array[random_index], rand_array[last]);
    return partition(rand_array, first, last);
}
template <typename T>
void quickSort(std::vector<T>& rand_array, int first, int last) {
    if (first < last) {
        int place = makeRandomPivotLast(rand_array, first, last);

        quickSort(rand_array, first, place - 1);
        quickSort(rand_array, place + 1, last);
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

    quickSort(rand_array, 0, size - 1);

    std::cout << "After: ";
    print_array(rand_array);

    return 0;
}