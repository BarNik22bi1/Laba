#include <iostream>
#include <vector>

template<typename T>
void selectionSort(std::vector<T>& rand_array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (rand_array[i] > rand_array[j]){
                min = j;
            }
        }
        std::swap(rand_array[i], rand_array[min]);
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

    selectionSort(rand_array,size);

    std::cout << "After: ";
    print_array(rand_array);

    return 0;
}