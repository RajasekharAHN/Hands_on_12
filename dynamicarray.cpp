#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::find

class DynamicArray {
private:
    std::vector<int> arr;
    int size;

public:
    DynamicArray() : size(0) {}

    void push_back(int value) {
        arr.push_back(value);
        size++;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        arr.pop_back();
        size--;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        arr.insert(arr.begin() + index, value);
        size++;
    }

    void remove(int value) {
        auto it = std::find(arr.begin(), arr.end(), value); // Fix: Use std::find from <algorithm>
        if (it == arr.end()) {
            throw std::invalid_argument("Value not found in array");
        }
        arr.erase(it);
        size--;
    }

    void resize(int new_size) {
        if (new_size < 0) {
            throw std::invalid_argument("New size must be non-negative");
        }
        arr.resize(new_size);
        size = std::min(new_size, size);
    }

    int at(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray dynArray;

    for (int i = 1; i <= 5; i++) {
        dynArray.push_back(i);
    }

    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < dynArray.getSize(); i++) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    dynArray.insert(2, 10);
    std::cout << "\nArray after inserting 10 at index 2:" << std::endl;
    for (int i = 0; i < dynArray.getSize(); i++) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    // Remove an element
    dynArray.remove(3);
    std::cout << "\nArray after removing 3:" << std::endl;
    for (int i = 0; i < dynArray.getSize(); i++) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    dynArray.resize(3);
    std::cout << "\nArray after resizing to 3 elements:" << std::endl;
    for (int i = 0; i < dynArray.getSize(); i++) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    dynArray.pop_back();
    std::cout << "\nArray after popping the last element:" << std::endl;
    for (int i = 0; i < dynArray.getSize(); i++) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
