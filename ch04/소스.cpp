#include <iostream>
#include <list>

int main() {

    int arr[] = { 10, 20, 30, 40 };

    // Convert array to list
    std::list<int> list(std::begin(arr), std::end(arr));

    // Remove an element
    list.remove(30);

    // Convert list to array
    int newArr[list.size()];
    std::copy(list.begin(), list.end(), newArr);

    for (int i : newArr) {
        std::cout << i << ' ';
    }

    return 0;
}